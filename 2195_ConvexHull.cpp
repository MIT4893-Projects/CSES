#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define endl "\n"
#define LLMAX INT64_MAX
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(), cin.tie()
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

#define point pair<int, int>
#define x first
#define y second

int calc(vector<point> points)
{
    int n = points.size();
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += (points[(i + 1) % n].x - points[i].x) * (points[(i + 1) % n].y + points[i].y);

    return result;
}

void solve()
{
    int n;
    cin >> n;

    vector<point> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].x >> arr[i].y;

    sort(arr.begin(), arr.begin() + n);

    vector<point> upper = {arr[0], arr[1]};

    for (int i = 2; i < n; i++)
    {
        while (upper.size() >= 2 && calc({upper[upper.size() - 2], upper[upper.size() - 1], arr[i]}) < 0)
            upper.pop_back();
        upper.push_back(arr[i]);
    }

    vector<point> lower = {arr[0], arr[1]};

    for (int i = 2; i < n; i++)
    {
        while (lower.size() >= 2 && calc({lower[lower.size() - 2], lower[lower.size() - 1], arr[i]}) > 0)
            lower.pop_back();
        lower.push_back(arr[i]);
    }

    cout << upper.size() + lower.size() - 2 << endl;
    for (int i = 0; i < upper.size(); ++i)
        cout << upper[i].x << ' ' << upper[i].y << endl;
    for (int i = 1; i < lower.size() - 1; ++i)
        cout << lower[i].x << ' ' << lower[i].y << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
