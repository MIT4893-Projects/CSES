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

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> towers;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;

        int idx = -1;
        int low = 0;
        int high = (int)towers.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (towers[mid].back() > val)
            {
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        if (idx == -1)
            towers.push_back(vector<int> {val});
        else
            towers[idx].push_back(val);
    }

    cout << towers.size();
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
