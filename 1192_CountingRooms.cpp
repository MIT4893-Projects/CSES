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

int n, m;
int result = 0;
vector<string> board;

bool isvalid(int i, int j)
{
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void loang(int i, int j)
{
    if (!isvalid(i, j))
        return;

    if (board[i][j] == '#')
        return;

    board[i][j] = '#';
    loang(i + 1, j);
    loang(i - 1, j);
    loang(i, j + 1);
    loang(i, j - 1);
}

void solve()
{
    cin >> n >> m;
    board.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> board[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == '.')
                ++result, loang(i, j);

    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
