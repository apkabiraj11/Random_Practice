#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e7 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

void solve() {
    ll p, q;
    cin >> p >> q;
    if(p % q){
    	cout << p << ln;
    	return;
    }

	map<ll,ll>mp;
	ll temp = q;
	for(ll i = 2; i * i <= temp; i++){
	    if(temp % i == 0){
	        while(temp % i == 0) {
	        	mp[i]++;
	        	temp /= i;
	        }
	    }
	}
	if(temp > 1) 
		mp[temp]++;

	ll mx = 1;
	for(auto [x, y] : mp){
		int cnt = 0;
		ll temp = p;
		while(temp % x == 0){
			cnt++;
			temp /= x;
		}
		ll need = cnt - y + 1; // this much of x count needs to be divided

		ll v = (ll) powl(x, need);
		mx = max(mx, p/v);
	}
	cout << mx << ln;
	    

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

