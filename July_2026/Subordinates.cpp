#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 2e5 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

int n;
vector<int>ar[N + 2];
vector<int>subtre(N + 2);
void dfs (int src){
	subtre[src] = 1;
	for(auto child : ar[src]){
		// if(child != src){
			dfs(child);
			subtre[src] += subtre[child];
		// }
	}
}
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++){
    	int x;
    	cin >> x;
    	// cout << x << " ";
    	ar[x].push_back(i);
    }
 
    dfs(1);

    for(int i = 1; i <= n; i++){
    	cout << subtre[i] - 1 << " ";
    }

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

