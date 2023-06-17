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

struct TreeNode
{
    TreeNode *left, *right;
    int l, r, val;

    TreeNode(int _l, int _r) : l(_l), r(_r) {}
};

struct SegmentTree
{
    TreeNode *root;
    vector<int> arr;

    SegmentTree(vector<int> arr)
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

    int Update(int idx, int val, TreeNode *curr)
    {
        int l = curr->l;
        int r = curr->r;

        if (idx < l || idx > r)
            return curr->val;

        if (l == r)
            return curr->val = val;

        return curr->val = min(Update(idx, val, curr->left), Update(idx, val, curr->right));
    }

    int Query(int left, int right, TreeNode *curr)
    {
        int l = curr->l;
        int r = curr->r;

        if (r < left || l > right)
            return LLMAX;

        if (left <= l && r <= right)
            return curr->val;

        return min(Query(left, right, curr->left), Query(left, right, curr->right));
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    SegmentTree segtree(arr);
    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            segtree.Update(a, b, segtree.root);
        else
            cout << segtree.Query(a, b, segtree.root) << endl;
    }
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
