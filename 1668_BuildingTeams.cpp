#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define endl "\n"
#define LLMAX INT64_MAX
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie()
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

int n, m;
array<vector<int>, 100005> edges;
array<bool, 100005> mark;
array<bool, 100005> result;

bool bfs(int root)
{
    queue<int> q;

    q.push(root);
    bool label = true;

    while (q.size())
    {
        int layersize = q.size();
        for (int i = 0; i < layersize; ++i)
        {
            int curr = q.front();
            q.pop();

            for (auto next : edges[curr])
                if (mark[next])
                {
                    if (label != result[next])
                        return false;
                }
                else
                {
                    mark[next] = true;
                    q.push(next);

                    result[next] = label;
                }
        }

        label = !label;
    }

    return true;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!mark[i])
            if (!bfs(i))
            {
                cout << "IMPOSSIBLE";
                return;
            }

    for (int i = 1; i <= n; ++i)
        cout << result[i] + 1 << ' ';
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
