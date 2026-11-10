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
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
struct SegmentTree {
    struct Node {
        ll mx1;
        ll mx2;

        Node(ll mx1 = LLONG_MIN, ll mx2 = LLONG_MIN) {
            this->mx1 = mx1;
            this->mx2 = mx2;
        }
    };

    vector<Node> tree;
    vector<ll> ar;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
        ar.resize(n + 1);
    }

    // ==================== OPERATION ====================

    Node merge(Node left, Node right) {
        Node res;

        // Maximum value
        res.mx1 = max(left.mx1, right.mx1);

        // Second maximum value
        res.mx2 = max(
            min(left.mx1, right.mx1),
            max(left.mx2, right.mx2)
        );

        return res;
    }

    // =================================================

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = Node(ar[l], LLONG_MIN);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if(l == r) {
            tree[node] = Node(val, LLONG_MIN);
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
            return Node(LLONG_MIN, LLONG_MIN);
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

    Node query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    /*
    SegmentTree st(n);

    for(int i = 1; i <= n; i++)
        cin >> st.ar[i];

    st.build();

    Example update
    st.update(3, 10);

    Example query
    Node ans = st.query(2, 5);

    cout << ans.mx1 << ln;
    cout << ans.mx2 << ln;
    */
};
void solve() {
    int n;
    cin >> n;

    SegmentTree st(n);
    for(int i= 1; i <= n; i++)
    	cin >> st.ar[i];

    st.build();

    int q;
    cin >> q;
    while(q--){
    	char c;
    	cin >> c;
    	if(c == 'Q'){
    		int l, r;
    		cin >> l >> r;
    		auto ans = st.query(l, r);
    		cout << ans.mx1 + ans.mx2 <<ln;
    	}
    	else {
    		ll pos, x;
    		cin >> pos >> x;
    		st.update(pos, x);
    	}
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    // int casee = 1;
    while(t--) {
        // cout << "Case " << casee << ": ";
        solve();
        // casee++;
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT 

***************/

