#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

struct SegmentTree {
    struct Node {
        ll val;
        ll mx;

        Node(ll val = 0, ll mx = 0) {
            this->val = val;
            this->mx = mx;
        }
    };

    vector<Node> tree;
    vector<ll> a;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
        a.resize(n + 1);
    }

    // ==================== OPERATION ====================

    Node merge(Node left, Node right) {
        Node res;

        // SUM
        res.val = left.val + right.val;

        // MAXIMUM PREFIX SUM
        res.mx = max(left.mx, left.val + right.mx);

        return res;
    }

    // =================================================

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = Node(a[l], max(0LL, a[l]));
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if(l == r) {
            tree[node] = Node(val, max(0LL, val));
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
        if(qr < l || r < ql) {
            return Node(0, 0);
        }

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

    void update(ll pos, ll val) {
        update(1, 1, n, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r).mx;
    }

    /*
    SegmentTree st(n);

    for(int i = 1; i <= n; i++)
        cin >> st.a[i];

    st.build();

    Example update
    st.update(3, 10);

    Example query
    cout << st.query(2, 5) << ln;
    */
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    for(int i = 1; i <= n; i++) {
        cin >> st.a[i];
    }

    st.build();

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            ll pos, val;
            cin >> pos >> val;

            st.update(pos, val);
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << st.query(l, r) << ln;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT

***************/