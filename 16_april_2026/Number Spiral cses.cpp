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
    ll y, x;
    cin >> y >> x;
    if(y < x) {
    	ll complete = (x - 1) * (x - 1);
    	if(complete % 2)
    		cout << complete + y << ln;
    	else {
    		cout << complete + x + (x - y) << ln;
    	}
    }
    else {
    	ll complete = (y - 1) * (y - 1);
    	if(complete % 2){
    		cout << complete + y + (y - x) << ln;
    	}
    	else cout << complete + x << ln;
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

