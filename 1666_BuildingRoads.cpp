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

map<int, vector<int>> edges;
map<int, bool> visited;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (q.size())
    {
        node = q.front();
        q.pop();
        for (auto subnode : edges[node])
            if (!visited[subnode])
                q.push(subnode), visited[subnode] = true;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> result;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            result.push_back(i);
            bfs(i);
        }
    }

    cout << result.size() - 1 << endl;
    for (int i = 1; i < result.size(); ++i)
        cout << result[i] << ' ' << result[i - 1] << endl;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}