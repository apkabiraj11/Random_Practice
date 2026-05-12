#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const ll N = 1e13, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
set<ll>st;
vector<ll>ar;
void precal(){
	ll temp = 1;

	for(ll i = 1; ; i++){
		temp *= i;
		if(temp >= N)
			break;
		st.insert(temp);
	}
	for(auto x : st){
		ar.push_back(x);
	}
}
void solve() {
    ll n;
    cin >> n;
    ll ans = 1e18;
    for(int i = 0; i < (1 << 15); i++){
    	ll temp = n;
    	ll cnt = 0;
    	for(int j = 0; j < 15; j++){
    		if(i & (1 << j)){
    			if(temp >= ar[j]){
    				temp -= ar[j];
    				cnt++;
    			}
    		}
    	}
    	ans = min(ans, cnt + __builtin_popcountll(temp));
    }
    cout << ans << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precal();
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

