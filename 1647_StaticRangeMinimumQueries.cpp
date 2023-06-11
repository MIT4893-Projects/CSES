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

struct TreeNode
{
    int l, r, val;
    TreeNode *left, *right;

    TreeNode(int _l, int _r) : l(_l), r(_r) {}
};

struct SegTree
{
    TreeNode *root;
    vector<int> arr;

    SegTree(vector<int> arr)
    {
        this->arr = arr;
        root = new TreeNode(1, arr.size());
        Build(root);
    }

    int Build(TreeNode *curr)
    {
        int l = curr->l;
        int r = curr->r;
        if (l == r)
            return curr->val = arr[l - 1];
        
        int mid = (l + r) / 2;
        curr->left = new TreeNode(l, mid);
        curr->right = new TreeNode(mid + 1, r);

        return curr->val = min(Build(curr->left), Build(curr->right));
    }

    int Query(int left, int right, TreeNode *curr)
    {
        int l = curr->l;
        int r = curr->r;

        if (r < left || l > right)
            return LLMAX;
        
        if (left <= l && r <= right)
            return curr->val;
        
        int mid = (l + r) / 2;
        return min(Query(left, right, curr->left), Query(left, right, curr->right));
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;
    
    SegTree segtree(arr);

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << segtree.Query(l, r, segtree.root) << endl;
    }
}

sint main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    solve();

    return 0;
}
