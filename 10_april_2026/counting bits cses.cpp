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
ll find_answer(ll n){
 
	if(n <= 0)
		return 0;
 	if(n == 1)
 		return 1;
	ll ans = 0;
	ll i = 0; 

	while((1LL << (i + 1)) <= n){
		i++;
	}
	ans = (1LL << (i - 1)) * i;
	ll temp = n - (1LL << i) + 1;
 
	return ans + temp + find_answer(n - (1LL << i));
}
void solve() {
	ll n;
	cin >> n;
 
	ll ans = find_answer(n);
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
