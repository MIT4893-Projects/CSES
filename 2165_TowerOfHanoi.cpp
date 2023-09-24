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
array<stack<int>, 3> pillar;
vector<pair<int, int>> curr, result;

void back(int n, int source = 1, int dest = 3, int temp = 2)
{
    if (n == 1)
    {
        cout << source << ' ' << dest << endl;
        return;
    }

    back(n - 1, source, temp, dest);
    cout << source << ' ' << dest << endl;
    back(n - 1, temp, dest, source);
}

void solve()
{
    cin >> n;
    
    cout << (1 << n) - 1 << endl;
    back(n);
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
