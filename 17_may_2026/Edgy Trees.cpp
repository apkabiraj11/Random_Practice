#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e5 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
int n, k;
vector<int>ar[N];
vector<bool>vis(N);
int cnt = 0;
void dfs(int src){
	vis[src] = true;
	cnt++;
	for(auto child : ar[src]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
void solve() {

    cin >> n >> k;
 		set<int>st;
 	for(int i = 1; i < n; i++){
 		int u, v, x;
 		cin >> u >> v >> x;
 		if(x == 0){
 			ar[u].push_back(v);
 			ar[v].push_back(u);
 			st.insert(u);
 			st.insert(v);
 		}
 	}

 	ll ans = 1;
 	for(int i = 1; i <= k; i++){
 		ans = (ans * n) % mod;
 	}

 	for(int node = 1; node <= n; node++){
 		if(!vis[node]){
 			
 			cnt = 0;
 			dfs(node);

 			ll p = 1;
 			for(int i = 1; i <= k; i++){
 				p = (p * cnt) % mod;
 			}
 			ans -= p;
 			ans = (ans + mod) % mod;
 		}
 	}
 	cout << ans << ln;



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

