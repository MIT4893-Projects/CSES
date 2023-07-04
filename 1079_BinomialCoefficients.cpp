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

vector<int> factorials(1000001);
const int MOD = 1000000007;
void preprocess()
{
    factorials[0] = 1;
    int f = 1;
    for (int i = 1; i <= 1000000; ++i)
    {
        f = f * i % MOD;
        factorials[i] = f;
    }
}

int exp(int a, int b)
{
    if (!b)
        return 1;
    int t = exp(a, b / 2);
    if (b % 2)
        return t * t % MOD * a % MOD;
    return t * t % MOD;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int temp = factorials[b] * factorials[a - b] % MOD;
    int inverse = exp(temp, MOD - 2);
    cout << factorials[a] * inverse % MOD << endl;
}

signed main()
{
    FAST_IO;

    preprocess();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
