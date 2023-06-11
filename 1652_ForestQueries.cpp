#include <bits/stdc++.h>
using namespace std;

using sint = signed int;
#define ll long long
#define ull unsigned ll
#define int ll
#define ss stringstream
#define uset unordered_set
#define umap unordered_map
#define vec vector

#define LLMAX INT64_MAX

#define in cin
#define out cout
#define input in
#define print out
#define GET(var) getline(cin, var)

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FORIR(i, a, n) for (int i = a; i < n; i++)
#define FORI(i, n) FORIR(i, 0, n)
#define FORR(a, n) FORIR(i, a, n)
#define FOR(n) FORIR(i, 0, n)
#define EACH(x, a) for (auto &x : a)
#define IF(cond, t, f) (cond ? t : f)
template <class T>
void OFILE(T finp, T fout)
{
    freopen(finp, "r", stdin), freopen(fout, "w", stdout);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pref(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            pref[i][j] = c == '*';
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1] << endl;
    }
}

sint main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    solve();

    return 0;
}
