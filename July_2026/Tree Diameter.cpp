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
vector<int>ar[N];
void dfs(int src, int par, vector<int>&level){


	for(auto child : ar[src]){
		if(child != par){
			level[child] = level[src] + 1;
			dfs(child, src, level);
		}
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		ar[u].push_back(v);
		ar[v].push_back(u);
	}   
	vector<int>level1(n + 2), level2(n + 2);

	dfs(1, 0, level1);

	int node;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		if(level1[i] > mx){
			node = i;
			mx = level1[i];
		}
	}

	dfs(node, 0, level2);

	node = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		if(level2[i] > mx){
			node = i;
			mx = level2[i];
		}
	}

	cout << mx << ln;


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

