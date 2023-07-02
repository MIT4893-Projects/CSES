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

    vector<int> people(n);
    for (int i = 0; i < n; ++i)
        cin >> people[i];

    sort(people.begin(), people.end());

    int aptr = 0;
    int bptr = n - 1;
    int result = 0;
    while (aptr <= bptr)
    {
        if (aptr == bptr)
        {
            ++result;
            break;
        }

        if (people[aptr] + people[bptr] <= x)
        {
            ++result;
            ++aptr;
            --bptr;
        }
        else
            --bptr, ++result;
    }
    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
