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
    int n, q;
    cin >> n >> q;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> pref[i];
        pref[i] ^= pref[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << (pref[r] ^ pref[l - 1]) << endl;
    }
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
