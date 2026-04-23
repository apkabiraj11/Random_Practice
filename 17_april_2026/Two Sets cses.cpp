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
    ll sum = 1LL * n * (n + 1) / 2;
    if(sum % 2){
    	no;
    	return;
    }
    ll target = sum / 2;
    vector<int>ar, br;
    for(int i = n; i >= 1; i--){
    	if(i <= target){
    		target -= i;
    		ar.push_back(i);
    	}
    	else br.push_back(i);
    }

    yes;
    cout << ar.size() << ln;
    for(auto x : ar)
    	cout << x << " ";
    cout << ln;
    cout << br.size() << ln;
    for(auto x : br)
    	cout << x << " ";
    cout << ln;
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

