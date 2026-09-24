#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
// using namespace __gnu_pbds; 
 
#define ll long long int 
#define ln '\n' 
#define yes cout << "YES" << ln 
#define no cout << "NO" << ln 
const int N = 1e6 + 9, mod = 998244353; 
 
// template <typename T> 
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Functions: 
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed) 
// 2. order_of_key(x) -> returns number of elements strictly smaller than x 
 
vector<ll> ar;
vector<ll> ways, sum, suffix;
int n;

void dfs(int i) {
    if(i == n) {
        ways[i] = 1;
        sum[i] = 0;
        return;
    }

    if(ways[i] != -1)
        return;

    dfs(i + 1);

    ll cnt = n - i;

    ways[i] = cnt * ways[i + 1] % mod;

    ll parentSum = (suffix[i + 1] - cnt * ar[i]) % mod;
    if(parentSum < 0) parentSum += mod;

    sum[i] = cnt * sum[i + 1] % mod;

    sum[i] += ways[i + 1] * parentSum % mod;
    sum[i] %= mod;
}

void solve() { 
    cin >> n;

    ar.assign(n + 1, 0);

    for(int i = 1; i <= n; i++)
        cin >> ar[i];

    sort(ar.begin() + 1, ar.end());

    suffix.assign(n + 2, 0);

    for(int i = n; i >= 1; i--) {
        suffix[i] = (suffix[i + 1] + ar[i]) % mod;
    }

    ways.assign(n + 1, -1);
    sum.assign(n + 1, 0);

    dfs(1);

    cout << sum[1] % mod << ln;
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