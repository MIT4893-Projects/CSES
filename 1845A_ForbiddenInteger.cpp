//* 219914875	Aug/22/2023 20:06UTC+7	Minh4893IT	A - Forbidden Integer	GNU C++14	Accepted	15 ms	0 KB

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
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        while (n--)
            cout << 1 << ' ';
        cout << endl;
        return;
    }

    if (n % 2 == 0 && k >= 2)
    {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for (int i = 0; i < n / 2; ++i)
            cout << "2 ";
        cout << endl;
        return;
    }

    if ((n - 3) % 2 == 0 && k >= 3)
    {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for (int i = 1; i < n / 2; ++i)
            cout << "2 ";
        cout << 3 << endl;
        return;
    }

    cout << "NO" << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
