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


void solve() {
   int n, k;
   cin >> n >> k;
   vector<ll>ar(n), br(n);
   ll sum = 0;
   for(int i = 0; i < n;i++){
    cin >> ar[i];
    sum += ar[i];
   }
   for(int i = 0; i < n; i++)
    cin >> br[i];

   k = k % 2;
   if(!k){
        ll cur = ar[0];
        ll mx = ar[0];
        for(int i = 1; i <n; i++){
            cur = max(ar[i], cur + ar[i]);
            mx = max(mx, cur);
        }
        cout << mx << ln;
        return;
   }
   ll ans = -1e18;
   vector<ll>pref(n), suf(n);
   pref[0] = max(0LL, ar[0]);
   for(int i = 1; i < n; i++){
        pref[i] = max(0LL, pref[i - 1] + ar[i]);
   }
   suf[n - 1] = max(0LL, ar[n - 1]);
   for(int i =  n - 2; i >= 0; i--){
        suf[i] = max(0LL, suf[i + 1] + ar[i]);
   }
   for(int i = 0; i < n; i++){
        ll l = i? pref[i - 1] : 0;
        ll r = (i < n - 1)? suf[i + 1] : 0;
        ans = max(ans, l + ar[i] + br[i] + r);
   }
   cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
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
