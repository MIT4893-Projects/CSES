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

const int MOD = 1e9 + 7;

void solve()
{
    int n, x;

    cin >> n >> x;

    vector<int> dp(x + 1);
    vector<int> coins(n);

    dp[0] = 1;

    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    for (int i = 1; i <= x; ++i)
        for (auto c : coins)
            if (i - c >= 0)
            {
                dp[i] += dp[i - c];
                dp[i] %= MOD;
            }

    cout << dp[x];
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
