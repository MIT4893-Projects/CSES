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

    int result = 1;
    map<int, int> count;
    int right = 1;
    int left = 1;
    for (; right <= n; ++right)
    {
        ++count[arr[right]];
        while (count[arr[left]] >= 2 || count[arr[right]] >= 2)
            --count[arr[left]], ++left;
        result = max(result, right - left + 1);
    }

    cout << result;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
