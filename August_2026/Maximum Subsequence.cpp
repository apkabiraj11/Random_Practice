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
ll x; 
int ar[45]; 
 
vector<ll> all1, all2; 
 
void ways(int l, int r, ll sum, vector<ll>& all){ 
    if(l == r){ 
        all.push_back(sum); 
        return; 
    } 
 
    ways(l + 1, r, sum, all); 
    ways(l + 1, r, sum + ar[l], all); 
} 
 
void solve() { 
    cin >> n >> x; 
 
    for(int i = 0; i < n; i++){ 
        cin >> ar[i]; 
    } 
 
    int mid = n / 2; 
 
    all1.clear();
    all2.clear();

    ways(0, mid, 0, all1); 
    ways(mid, n, 0, all2); 
    

        
    for(ll &sum : all1)
        sum %= x;
    for(ll &sum : all2)
        sum %= x;

    sort(all1.begin(), all1.end()); 
    sort(all2.begin(), all2.end()); 

    ll ans = 0; 
 
    for(ll sum : all1){ 
        ans = max(ans, sum);
        ll l = 0, r = all2.size() - 1;
        ll temp = 0;
        while(l <= r){
            int mid = (r + l) / 2;
            if(sum + all2[mid] < x){
                temp = sum + all2[mid];
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans = max(ans, temp);
    } 

    // for(ll sum : all2){
    //     ans = max(ans, sum);
    // }

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