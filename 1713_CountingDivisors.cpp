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

vector<int> primeDivisors(1000001);

void sieve(int n = 1000000)
{
    for (int i = 2; i <= n; ++i)
        if (!primeDivisors[i])
            for (int j = i; j <= n; j += i)
                primeDivisors[j] = i;
}

void solve()
{
    int n;
    cin >> n;

    int result = 1;
    while (n > 1)
    {
        int countDiv = 0;
        int maxPrimeDiv = primeDivisors[n];

        while (n % maxPrimeDiv == 0)
        {
            n /= maxPrimeDiv;
            ++countDiv;
        }

        result *= countDiv + 1;
    }

    cout << result << endl;
}

signed main()
{
    FAST_IO;

    sieve();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
