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
    vector<int> idx(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        idx[val] = i;
    }

    int result = 1;
    int last = idx[1];
    for (int i = 2; i <= n; ++i)
    {
        result += idx[i] < last;
        last = idx[i];
    }
    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
