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

int n;
array<point, 100000> points;

istream &operator>>(istream &is, point &p)
{
    return is >> p.x >> p.y;
}

int area()
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        res += (points[j].x - points[i].x) * (points[j].y + points[i].y);
    }

    return abs(res);
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> points[i];

    int pointOnBoundary = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        pointOnBoundary += __gcd(abs(points[i].x - points[j].x), abs(points[i].y - points[j].y));
    }

    cout << (area() - pointOnBoundary) / 2 + 1 << ' ' << pointOnBoundary;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
