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

    map<int, vector<int>> count;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        count[val].push_back(i + 1);
    }

    for (auto p : count)
    {
        if (x - p.first == p.first)
        {
            if (p.second.size() >= 2)
            {
                cout << p.second[0] << ' ' << p.second[1];
                return;
            }
        }
        else
            if (p.second.size() && count[x - p.first].size())
            {
                cout << p.second[0] << ' ' << count[x - p.first][0];
                return;
            }
    }

    cout << "IMPOSSIBLE";
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
