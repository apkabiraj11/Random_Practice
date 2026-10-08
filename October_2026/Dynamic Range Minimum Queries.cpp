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
        ll val;

        Node(ll val = 0) {
            this->val = val;
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

        // 1. SUM
        // res.val = left.val + right.val;

        // 2. MIN
        res.val = min(left.val, right.val);

        // 3. MAX
        // res.val = max(left.val, right.val);

        // 4. GCD
        // res.val = gcd(left.val, right.val);

        // 5. XOR
        // res.val = left.val ^ right.val;

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

    void update(int node, int l, int r, int pos, ll val) {
        if(l == r) {
            tree[node] = Node(val);
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

            // SUM / XOR / GCD
            // return Node(0);

            // MIN
            return Node(LLONG_MAX);

            // MAX
            // return Node(LLONG_MIN);
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

    void update(int pos, ll val) {
        update(1, 1, n, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r).val;
    }

    /*
    SegmentTree st(n);

    for(int i = 1; i <= n; i++)
        cin >> st.ar[i];

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
    for(int i = 1; i <= n; i++){
    	cin >> st.ar[i];
    }
    st.build();
    while(q--){
    	int type;
    	cin >> type;
    	if(type == 1){
    		int pos;
			ll val;
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

