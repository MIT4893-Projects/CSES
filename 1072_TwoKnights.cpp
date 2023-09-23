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
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1) << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
