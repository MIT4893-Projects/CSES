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

int n, k;
vector<int> arr;

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

vector<int> comb;
vector<int> combs;
void combinators(int i = 0)
{
    if (i >= arr.size())
    {
        if (comb.empty())
            return;

        int l = comb[0];
        for (int i = 1; i < comb.size(); ++i)
            l = lcm(l, comb[i]);

        if (comb.size() % 2 == 0)
            l *= -1;
        combs.push_back(l);
        return;
    }

    comb.push_back(arr[i]);
    combinators(i + 1);
    comb.pop_back();

    combinators(i + 1);
}

void solve()
{
    cin >> n >> k;

    arr = vector<int>(k);

    for (int i = 0; i < k; ++i)
        cin >> arr[i];

    int result = 0;

    combinators();
    for (auto elem : combs)
        result += n / elem;
    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
