#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define int long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x


int n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    sort(s.begin(),s.end());
    int c1 = count(s.begin(),s.end(), '+');
    int c2 = n - c1; 
    int q;
    cin >> q;
    while(q--){
    	int a, b;
    	cin >> a >> b;
    	if(c1 == c2){
    		yes;
    		continue;
    	}
    	if(a == b){
    		no;
    		continue;
    	}
    	int l = lcm(a, b);
    	int x = l / a, y = l / b;

    	if(abs(c1 - c2) % abs(x - y) == 0){
    		int round = abs(c1 - c2) / abs(x - y);
    		if((x + y) * round > n)
    			no;
    		else yes;
    	}
    	else no;
    }
}

int32_t main() {
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

