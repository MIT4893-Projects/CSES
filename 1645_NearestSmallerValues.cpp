#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ss stringstream
#define endl "\n"
#define LLMAX INT64_MAX
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

void solve()
{
    int n;
    cin >> n;

    array<int, 200005> arr;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    vector<int> minIdx = {1};
    cout << 0 << ' ';

    for (int i = 2; i <= n; ++i)
    {
        while (minIdx.size() && arr[minIdx.back()] >= arr[i])
            minIdx.pop_back();

        cout << IF(minIdx.empty(), 0ll, minIdx.back()) << ' ';
        minIdx.push_back(i);
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
