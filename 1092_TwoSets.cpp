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

    int sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << "NO";
        return;
    }

    cout << "YES" << endl;

    if (n % 2)
    {
        cout << n / 2 << endl;
        for (int i = 1; i <= n; ++i)
            if (i <= n / 4 || i >= n - n / 4)
                cout << i << ' ';
        cout << endl;

        cout << n / 2 + n % 2 << endl;
        for (int i = n / 4 + 1; i < n - n / 4; ++i)
            cout << i << ' ';
    }
    else
    {
        cout << n / 2 << endl;
        for (int i = 1; i <= n; ++i)
            if (i <= n / 4 || i > n - n / 4)
                cout << i << ' ';
        cout << endl;

        cout << n / 2 + n % 2 << endl;
        for (int i = n / 4 + 1; i <= n - n / 4; ++i)
            cout << i << ' ';
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
