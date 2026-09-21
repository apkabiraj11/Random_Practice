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
vector<ll>level(N + 2), sub(N + 2), ans(N + 2);
void dfs(int src, int par){
	sub[src] = 1;
	for(auto child : ar[src]){
		if(child != par){
			level[child] = level[src] + 1;
			dfs(child, src);
			sub[src] += sub[child];
		}
	}
}

void dfs2(int src, int par){
	for(auto child : ar[src]){
		if(child != par){
			ans[child] = ans[src]  + n - 2LL*sub[child];
			dfs2(child, src);
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

	dfs(1, 0);

	ans[1] = 0;
	for(int i = 1; i <= n; i++){
		ans[1] += level[i];
	}

	dfs2(1, 0);

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";


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

