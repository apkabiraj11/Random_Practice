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
    int n, w;
    cin >> n >> w;
    vector<ll>ar(n);
    int mn = 0, mx = 0, sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    	sum += ar[i];
    	mn = min(mn, sum);
    	mx = max(mx, sum);
    }

    if(mx > w){
    	cout << 0 << ln;
    	return;
    }

  	if(mn < 0){
  		mn = -mn;
  	}
  	if(mx <= 0) mx = w;
  	else mx = w - mx;

  	if(mn > mx){
  		cout << 0 << ln;
  	} 
    else cout << mx - mn + 1<< ln;

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

