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
    vector<int>ar(n);
    for(int i = 0; i < n; i++)
    	cin >> ar[i];
  	vector<int>mx(n + 1), mn(n + 1);
  	mx[0] = ar[0];
  	for(int i = 1; i < n; i++)
  		mx[i] = max(mx[i - 1], ar[i]);

  	mn[n - 1] = ar[n - 1];
  	for(int i = n - 2; i >= 0; i--){
  		mn[i] = min(mn[i + 1], ar[i]);
  	}

  	int dif = -mod;
  	for(int i = 0;i < n; i++){
  		dif = max(dif, mx[i] - mn[i]);
  	}
    if(dif <= 0){
    	cout << 0 << ln;
    }
    else {
  		int ans = log2(dif);
  		cout << ans + 1<< ln;
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

