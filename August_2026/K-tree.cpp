#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln

const int N = 1000, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

int n, k, d;
ll dp[N][N];

ll fun(int target, int mx) {
    if (target == 0 )
        return mx >= d;

    if (target < 0)
        return 0;

    if (dp[target][mx] != -1)
        return dp[target][mx];

    ll ans = 0;

    for (int i = 1; i <= k; i++) {
        ans += fun(target - i, max(mx, i));
        ans %= mod;
    }

    return dp[target][mx] = ans;
}

void solve() {
    cin >> n >> k >> d;

    memset(dp, -1, sizeof(dp));

    ll ans = fun(n, 0);


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