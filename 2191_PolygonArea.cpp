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

#define point pair<int, int>
#define x first
#define y second

void solve()
{
    int n;
    cin >> n;

    array<point, 1000> arr;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].x >> arr[i].y;

    int result = 0;
    for (int i = 0; i < n; ++i)
        result += (arr[(i + 1) % n].x - arr[i].x) * (arr[(i + 1) % n].y + arr[i].y);
    cout << abs(result);
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
