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

int n;

void solve() {
    cin >> n;

    vector<ll> ar(n);

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }

    if (n < 3 || sum % 3 != 0) {
        cout << 0 << ln;
        return;
    }

    ll target = sum / 3;

    ll pref = 0;
    ll cnt = 0;
    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        pref += ar[i];

        if (pref == 2 * target) {
            ans += cnt;
        }

        if (pref == target) {
            cnt++;
        }
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

/**************

LEARNING IS FUN
SO ENJOY IT

***************/