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

void solve()
{
    int x, y;
    cin >> x >> y;

    int layer = max(x, y);
    int past = (layer - 1) * (layer - 1);
    if (layer % 2)
        if (y < x)
            cout << past + y << endl;
        else
            cout << past + layer + layer - x << endl;
    else
        if (x < y)
            cout << past + x << endl;
        else
            cout << past + layer + layer - y << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
