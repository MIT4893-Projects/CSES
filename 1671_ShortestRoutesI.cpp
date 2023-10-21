#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define endl "\n"
#define LLMAX INT64_MAX
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

int n, m;
array<int, 100005> dist;
array<bool, 100005> visited;
array<vector<pair<int, int>>, 100005> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void preprocess()
{
    dist.fill(LLMAX);
    dist[1] = 0;

    visited.fill(false);
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    pq.push({0, 1});
    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';
}

signed main()
{
    FAST_IO;

    preprocess();

    // MULTI
    solve();

    return 0;
}
