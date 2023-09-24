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

int result = 0;
const int n = 8;
array<array<bool, 8>, 8> mark;
map<int, bool> mainDiag, subDiag, col;

void back(int i = 0)
{
    if (i == 8)
    {
        ++result;
        return;
    }

    for (int j = 0; j < 8; ++j)
    {
        if (!mark[i][j])
            continue;

        if (!mainDiag[i + j] && !subDiag[i - j] && !col[j])
        {
            mainDiag[i + j] = true;
            subDiag[i - j] = true;
            col[j] = true;

            back(i + 1);

            mainDiag[i + j] = false;
            subDiag[i - j] = false;
            col[j] = false;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;

            mark[i][j] = c == '.';
        }
    
    back();

    cout << result;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
