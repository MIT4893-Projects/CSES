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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n), apartments(m);

    for (int i = 0; i < n; ++i)
        cin >> applicants[i];
    for (int i = 0; i < m; ++i)
        cin >> apartments[i];
    
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int aptr = 0;
    int bptr = 0;
    int result = 0;
    while (aptr < n && bptr < m)
    {
        if (abs(applicants[aptr] - apartments[bptr]) <= k)
        {
            ++result;
            ++aptr;
            ++bptr;
        }
        else if (applicants[aptr] < apartments[bptr])
            ++aptr;
        else
            ++bptr;
    }

    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
