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

#define task pair<int, int>
#define dura first
#define dline second

void solve()
{
    int n;
    cin >> n;

    vector<task> arr(n);
    for (int i = 0 ;i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    int result = 0;
    int currtime = 0;
    for (int i = 0; i < n; ++i)
    {
        currtime += arr[i].dura;
        result += arr[i].dline - currtime;
    }

    cout << result;
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
