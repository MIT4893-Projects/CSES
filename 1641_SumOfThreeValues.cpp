#include <bits/stdc++.h>
using namespace std;

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

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first, arr[i].second = i;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i)
    {
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int target = x - arr[i].first;
            if (arr[i].second != arr[l].second && arr[i].second != arr[r].second && arr[l].first + arr[r].first == target)
            {
                cout << arr[i].second + 1 << ' ' << arr[l].second + 1 << ' ' << arr[r].second + 1;
                return;
            }
            if (arr[l].first + arr[r].first < target)
                ++l;
            else
                --r;
        }
    }

    cout << "IMPOSSIBLE";
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
