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

    map<int, int> pref;
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        ++pref[a], --pref[b + 1];
    }

    int result = 0;
    int sum = 0;
    for (auto elem : pref)
        result = max(result, sum += elem.second);

    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
