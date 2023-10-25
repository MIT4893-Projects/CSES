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
vector<string> result = {"0", "1"};

void back(int i = 1)
{
    if (i >= n)
        return;

    vector<string> copy(result.begin(), result.end());
    result.clear();

    for (auto elem : copy)
        result.push_back('0' + elem);
    for (auto it = copy.rbegin(); it != copy.rend(); ++it)
        result.push_back('1' + *it);

    back(i + 1);
}

void solve()
{
    cin >> n;

    back();

    for (auto &elem : result)
    {
        for (int i = 0; i < n - elem.size(); ++i)
            cout << '0';
        cout << elem << endl;
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
