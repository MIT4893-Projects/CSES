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

#define x first
#define y second
#define point pair<int, int>

void solve()
{
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    int s = (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
    
    cout << IF(!s, "TOUCH", IF(s < 0, "LEFT", "RIGHT")) << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
