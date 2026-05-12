#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 4e4 + 5, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
vector<int>ar;
vector<int>dp(N + 1);
void precal(){
	for(int i = 1; i < N; i++){
		string x = to_string(i);
		int l = 0, r = x.size() - 1;
		bool ok = true;
		while(l <= r){
			if(x[l] != x[r]){
				ok = false;
				break;
			}
			l++, r--;
		}
		if(ok)
			ar.push_back(i);
	}
	dp[0] = 1;
    for(auto x : ar){
    	for(int i = x; i < N; i++){
    		dp[i] = (dp[i] + dp[i - x]) % mod;
    	}
    }
    
}

void solve() {
	int n;
    cin >> n;
    cout << dp[n] << ln;
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

