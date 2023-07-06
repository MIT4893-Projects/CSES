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

struct node
{
    vector<int> children;
};

vector<vector<int>> tree;
vector<int> result;

int recur(int i)
{
    for (auto elem : tree[i])
        result[i] += recur(elem) + 1;
    return result[i];
}

void solve()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    result.resize(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        int val;
        cin >> val;
        tree[val].push_back(i);
    }

    recur(1);
    for (int i = 1; i <= n; ++i)
        cout << result[i] << ' ';
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
