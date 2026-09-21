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
    ll k;
    cin >> k;
 
    ll digits = 0;
    string high = "9", low = "0";
    ll multiplyer = 1;
    while(1){
    	ll dif = stoll(high) - stoll(low);
    	ll totaldigits = dif * multiplyer;
 
    	if(digits + totaldigits >= k){
    		break;
    	}
 
    	digits += totaldigits;
    	low = high;
    	high += "9";
    	multiplyer++;
    }
 
    ll l = stoll(low) + 1;
    ll r = stoll(high);
 
    ll ans = stoll(low);
    while(l <= r){
    	ll mid = (r + l) / 2;
 
    	ll dif = mid - stoll(low);
    	ll totaldigits = dif * multiplyer;
 
    	if(digits + totaldigits < k){
    		ans = mid;
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }
 
   	ll dif = ans - stoll(low);
	ll totaldigits = dif * multiplyer;
	digits += totaldigits;
 
	string temp = to_string(ans + 1) + to_string(ans + 2);
	for(int i = 0; i < temp.size(); i++){
		if(digits + i + 1 == k){
			cout << temp[i] << ln;
			return;
		}
	}
 
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
