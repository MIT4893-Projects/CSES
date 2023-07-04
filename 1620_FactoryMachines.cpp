#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define uset unordered_set
#define umap unordered_map
#define mmap multimap
#define mset multiset
#define pq priority_queue
#define endl "\n"

#define LLMAX INT64_MAX
#define GET(var) getline(cin, var)
#define EACH(x, a) for (auto &x : a)
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie()

array<int, 200005> machines;
int n, t;

bool check(int time)
{
    int make = 0;
    for (int i = 0; i < n; ++i)
    {
        make += time / machines[i];
        if (make >= t)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> t;

    for (int i = 0; i < n; ++i)
        cin >> machines[i];

    int low = 0;
    int high = 1e18 + 1;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            high = mid - 1;
            result = mid;
        }
        else
            low = mid + 1;
    }

    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
