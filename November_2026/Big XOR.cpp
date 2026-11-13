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
	int n;
	cin >> n;
	int xorr = 0;
	int orr = 0;
    for(int i = 1; i <= n; i++){
    	xorr ^= i;
    	orr |= i;
    }

    vector<int>ans(n + 2);
    for(int i = 25; i > 0; i--){
    	if(!(xorr & (1 << i))){
    		int val = 1 << (i - 1);
    		if(val <= n){
    			ans[val] = 1;
    			xorr ^= val;
    			val *= 2;
    			xorr ^= val;
    		}
    	}
    }

    // cout << orr << " " << xorr << ln;
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " " ;
    }
    cout << ln;

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

