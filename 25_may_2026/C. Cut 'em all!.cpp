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
vector<int> ar[N];
vector<int>d(N), vis(N);
int ans = 0;
int n;
void dfs(int src){
	d[src] = 1;
	vis[src] = 1;
	for(auto child : ar[src]){
		if(!vis[child]){
			dfs(child);
			d[src] += d[child];
			if(d[child] % 2 == 0){
				ans++;
			}
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

    if(n % 2){
    	cout << -1 << ln;
    	return;
    }
    int leaf = -1;
    for(int i = 1; i <= n; i++){
    	if(ar[i].size() == 1){
    		leaf = i;
    		break;
    	}
    }
    dfs(leaf);
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

