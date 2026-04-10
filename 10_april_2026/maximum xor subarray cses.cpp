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
struct Trie {
    struct Node {
        Node* child[2];
        Node() {
            child[0] = child[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new Node();
            cur = cur->child[bit];
        }
    }

    int query(int num) {
        Node* cur = root;
        int res = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (cur->child[1 - bit]) {
                res |= (1 << i);
                cur = cur->child[1 - bit];
            } else {
                cur = cur->child[bit];
            }
        }

        return res;
    }
};

int maxSubarrayXor(vector<int>& a) {
    Trie trie;
    trie.insert(0);

    int px = 0, ans = 0;

    for (int x : a) {
        px ^= x;
        ans = max(ans, trie.query(px));
        trie.insert(px);
    }

    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int>ar(n);
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    }
    ll ans = maxSubarrayXor(ar);
    cout << ans << ln;
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

