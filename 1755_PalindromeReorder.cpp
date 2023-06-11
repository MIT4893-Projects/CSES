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
    string s;
    GET(s);

    map<char, int> count;
    vector<pair<char, int>> odd;

    for (auto c : s)
        ++count[c];

    for (auto p : count)
    {
        if (p.second & 1)
            odd.push_back(p);
        if (odd.size() > 1)
        {
            cout << "NO SOLUTION";
            return;
        }
    }

    if (odd.size())
        count.erase(odd.front().first);

    string left, right;
    for (auto p : count)
        for (int i = 0; i < p.second / 2; ++i)
        {
            left += p.first;
            right += p.first;
        }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), greater<char>());

    cout << left;

    if (odd.size())
        while (odd[0].second--)
            cout << odd[0].first;
    
    cout << right;
}

sint main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    solve();

    return 0;
}
