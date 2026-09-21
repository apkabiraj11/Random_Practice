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

// template
// using ordered_set = tree<T, null_type, less, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

int n, m;

ll dp[25][1005];

ll dfs(int pos, int last) {

    if (pos == 2 * m)
        return 1;

    // Already calculated
    if (dp[pos][last] != -1)
        return dp[pos][last];

    ll ans = 0;

    for (int x = last; x <= n; x++) {
        ans += dfs(pos + 1, x);
        ans %= mod;
    }

    return dp[pos][last] = ans;
}

void solve() {
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    ll ans = 0;

    // Choose the first value
    for (int x = 1; x <= n; x++) {
        ans += dfs(1, x);
        ans %= mod;
    }

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

/*********************************

LEARNING IS FUN
SO ENJOY IT

*********************************/