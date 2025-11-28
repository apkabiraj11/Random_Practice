#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 100+ 9, mod = 998244353;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
int n;
vector<int>ar(N), br(N);
map<tuple<int,int,int>, ll> dp;
int f(int i, int prev1, int prev2){

    if(i == n)
        return 1;
    auto key = make_tuple(i, prev1, prev2);
    if (dp.count(key)) return dp[key];

    int ans = 0;
    if(prev1 <= ar[i] && prev2 <= br[i]){
        ans = (ans + f(i + 1, ar[i], br[i])) % mod;
    }
    if(prev1 <= br[i] && prev2 <= ar[i]){
        ans = (ans + f(i + 1, br[i], ar[i])) % mod;
    }
    return dp[key] = ans;
}
void solve() {

   dp.clear();

   cin >> n;

   for(int i = 0; i < n; i++) cin >> ar[i];
   for(int i = 0; i < n; i++) cin >> br[i];


   int ans = f(0, 0, 0);
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

