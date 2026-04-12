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
    int n, k;
    cin >> n >> k;
    vector<int>ar(n + 1), br(n + 1);
    for(int i = 1; i <= n;i++)
    	cin >> ar[i];
    for(int i = 1; i <= n; i++) {
    	cin >> br[i];
    }

    for(int i = 1; i <= n - k; i++){
    	if(br[i] == -1){
    		br[i] = ar[i];
    	}
    	if(br[n - i + 1] == -1){
    		br[n - i + 1] = ar[n - i + 1];
    	}

    	if(br[i] != -1 && br[i] != ar[i]){
    		no;
    		return;
    	}
    	if(br[n - i + 1] != -1 && br[n - i + 1] != ar[n - i + 1]){
    		no;
    		return;
    	}
    }

    map<int,int>mp;
    for(auto x : br){
    	if(x >= 0){
    		if(mp.count(x)){
    			no;
    			return;
    		}
    		mp[x]++;
    	}
    	// cout << x << " ";
    }

    yes;
    
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

