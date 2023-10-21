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

int n, m, q;
array<array<int, 505>, 505> dist;

const int INF = 250000000000000;

void solve()
{
    for (auto &elem : dist)
        elem.fill(INF);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << IF(dist[a][b] == INF, -1ll, dist[a][b]) << endl;
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
