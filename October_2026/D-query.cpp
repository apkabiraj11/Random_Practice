#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct SegmentTree {
    struct Node {
        set<int> st;

        Node() {}

        Node(int x) {
            st.insert(x);
        }
    };

    vector<Node> tree;
    vector<int> ar;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
        ar.resize(n + 1);
    }

    // ==================== OPERATION ====================

    Node merge(Node left, Node right) {
        Node res;

        for(auto x : left.st)
            res.st.insert(x);

        for(auto x : right.st)
            res.st.insert(x);

        return res;
    }

    // =================================================

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = Node(ar[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            tree[node] = Node(val);
            ar[pos] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql)
            return Node();

        if(ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    // ----------- Easy-to-use functions -----------

    void build() {
        build(1, 1, n);
    }

    void update(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    set<int> query(int l, int r) {
        return query(1, 1, n, l, r).st;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> ar[i];

    SegmentTree st(n);
    st.ar = ar;
    st.build();

    int q;
    cin >> q;

    while(q--) {

            int l, r;
            cin >> l >> r;
            set<int> ans = st.query(l, r);
            cout << ans.size() << ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT

***************/