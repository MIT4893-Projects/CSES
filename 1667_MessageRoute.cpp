#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define uset unordered_set
#define umap unordered_map
#define mmap multimap
#define mset multiset
#define pq priority_queue
#define endl "\n"

#define LLMAX INT64_MAX
#define GET(var) getline(cin, var)
#define EACH(x, a) for (auto &x : a)
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie()

void solve()
{
    int n, m;
    cin >> n >> m;

    map<int, vector<int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    map<int, int> path;
    map<int, bool> visited;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (q.size())
    {
        int node = q.front();
        q.pop();

        for (auto sub : edges[node])
            if (!visited[sub])
            {
                path[sub] = node;
                visited[sub] = true;
                q.push(sub);
            }
        // if (visited[n])
        // {
        //     for (auto p : visited)  
        //         cerr << p.first << ' ' << boolalpha << p.second << endl;
        //     break;
        // }
    }

    if (!visited[n])
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> result;
    while (n != 1)
    {
        result.push_back(n);
        n = path[n];
    }

    reverse(result.begin(), result.end());
    cout << result.size() + 1 << endl;
    cout << "1 ";
    for (auto elem : result)
        cout << elem << ' ';
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
