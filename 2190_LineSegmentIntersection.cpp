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

istream &operator>>(istream &is, point &p)
{
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, point p)
{
    return os << p.x << ' ' << p.y << " | ";
}

int calc(vector<point> points)
{
    int area = 0;
    int n = points.size();

    for (int i = 0; i < n; ++i)
        area += (points[(i + 1) % n].x - points[i].x) * (points[(i + 1) % n].y + points[i].y);

    if (!area)
        return area;
    return area / abs(area);
}

bool check(point a, point b, point c)
{
    return (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x)) && (c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y));
}

void solve()
{
    vector<point> points(4);
    for (auto &p : points)
        cin >> p;

    int area1 = calc({points[0], points[1], points[2]});
    int area2 = calc({points[0], points[1], points[3]});
    int area3 = calc({points[2], points[3], points[0]});
    int area4 = calc({points[2], points[3], points[1]});

    if (area1 != area2 && area3 != area4)
    {
        cout << "YES" << endl;
        return;
    }

    if (area1 == 0 && check(points[0], points[1], points[2]))
        cout << "YES" << endl;
    else if (area2 == 0 && check(points[0], points[1], points[3]))
        cout << "YES" << endl;
    else if (area3 == 0 && check(points[2], points[3], points[0]))
        cout << "YES" << endl;
    else if (area4 == 0 && check(points[2], points[3], points[1]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
