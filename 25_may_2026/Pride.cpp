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

// bool check_primes(int x){
// 	for(int i = 2; 1LL * i * i < x; i++){
// 		if(x % i == 0)
// 			return false;
// 	}
// 	return true;
// }
void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    int gcd = 0;
    int ones = 0;
    for(int i = 0; i < n; i++) {
    	cin >> ar[i];
    	if(ar[i] == 1)
    		ones++;
    	gcd = __gcd(gcd, ar[i]);
    }
    if(gcd != 1){
    	cout << -1 << ln;
    	return;
    }
    if(ones > 0){
    	cout << n - ones << ln;
    	return;
    }
    int mn = INT_MAX;
    int idx = -1;
   	for(int i = 0; i < n; i++){
   		int g = 0;
   		for(int j = i; j < n; j++){
   			g = __gcd(g, ar[j]);
   			if(g == 1){
   				int len = j - i + 1;
   				if(len < mn){
   					mn = len;
   					idx = i;
   				}
   			}
   		}
   	}
   	cout << mn - 1 + (n - 1) << ln;





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

