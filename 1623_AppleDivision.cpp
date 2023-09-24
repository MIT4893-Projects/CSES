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

int n;
array<int, 20> arr;
int result = LLMAX;

void back(int i = 0, int sum1 = 0, int sum2 = 0)
{
    if (i == n)
    {
        result = min(result, abs(sum1 - sum2));
        return;
    }

    back(i + 1, sum1 + arr[i], sum2);
    back(i + 1, sum1, sum2 + arr[i]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    back();

    cout << result;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
