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
    int n, x;
    cin >> n >> x;

    vector<int> dp(x + 1, LLMAX);
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];

        if (coins[i] <= x)
            dp[coins[i]] = 1;
    }

    for (int i = 1; i <= x; ++i)
    {
        for (int c : coins)
        {
            if (i - c < 1)
                continue;

            if (dp[i - c] == LLMAX)
                continue;
            dp[i] = min(dp[i - c] + 1, dp[i]);
        }
    }

    cout << IF(dp[x] != LLMAX, dp[x], -1);
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
