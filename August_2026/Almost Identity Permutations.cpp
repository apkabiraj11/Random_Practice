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

ll C[1005][1005];

void precal(){
    C[0][0] = 1;

    for (int i = 1; i < 1005; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
        }
    }
}
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int>d = {0, 0, 1, 2, 9};

    ll ans = 0;
    for(int i = 0; i <= k; i++){
        ans += C[n][i] * d[i];
    }
    cout << ans + 1 << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precal();

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

