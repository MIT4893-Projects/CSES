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
array<array<bool, 1005>, 1005> visited;
array<array<short, 1005>, 1005> path;
array<string, 1005> board;
pair<int, int> adj[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char direction[5] = "RDLU";
pair<int, int> start, stop;

bool valid(pair<int, int> pos)
{
    return 1 <= pos.first && pos.first <= n && 1 <= pos.second && pos.second <= m;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (q.size())
    {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            auto elem = adj[i];
            pair<int, int> next = {curr.first + elem.first, curr.second + elem.second};

            if (!valid(next))
                continue;
            if (visited[next.first][next.second])
                continue;
            if (board[next.first][next.second] == '#')
                continue;

            path[next.first][next.second] = i;
            visited[next.first][next.second] = true;
            q.push(next);

            if (next == stop)
                return;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> board[i], board[i] = ' ' + board[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (board[i][j] == 'A')
                start = {i, j};
            else if (board[i][j] == 'B')
                stop = {i, j};
        }

    bfs();

    if (!visited[stop.first][stop.second])
    {
        cout << "NO";
        return;
    }

    string result;
    while (stop != start)
    {
        result += direction[path[stop.first][stop.second]];

        auto prev = adj[path[stop.first][stop.second]];
        stop.first -= prev.first;
        stop.second -= prev.second;
    }

    reverse(result.begin(), result.end());

    cout << "YES" << endl;
    cout << result.size() << endl;
    cout << result;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
