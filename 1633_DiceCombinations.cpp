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

    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = max(0ll, i - 6); j < i; ++j)
        {
            dp[i] += dp[j];
            dp[i] %= 1000000007;
        }

    cout << dp[n];
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
