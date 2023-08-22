//* 219909175	Aug/22/2023 19:15UTC+7	Minh4893IT	B - Longest Divisors Interval	GNU C++14	Accepted	46 ms	0 KB

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

void solve()
{
    int n;
    cin >> n;

    int result = 1;
    for (; n % result == 0; ++result)
        ;
    cout << result - 1 << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
