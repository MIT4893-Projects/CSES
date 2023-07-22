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
    int n, m;
    cin >> n >> m;
    mset<int> h;
    vector<int> t(m);

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        h.insert(val);
    }
    for (auto &elem : t)
        cin >> elem;

    for (auto elem : t)
    {
        mset<int>::iterator it = h.lower_bound(elem);
        if (*it == elem)
        {
            cout << *it << endl;
            h.erase(it);
        }
        else
        {
            if (it == h.begin())
                cout << -1 << endl;
            else
            {
                cout << *(--it) << endl;
                h.erase(it);
            }
        }
    }
}

signed main()
{
    FAST_IO;
    solve();

    return 0;
}
