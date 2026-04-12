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

int n, m;
vector<int> ar[N];
vector<int> colour(N, -1);
vector<bool>vis(N);
bool bipar = 0;
int c0, c1;

void dfs(int src, int color) {
    vis[src] = true;
    colour[src] = color;

    if(color == 0) c0++;
    else c1++;

    for(auto child : ar[src]){
        int newcolour = 1 - color;
		if(vis[child] && colour[child] == colour[src]){
			bipar = false;
		}

        if(!vis[child]){
            dfs(child, newcolour);
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	ar[u].push_back(v);
    	ar[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		bipar = true;
    		c0 = 0, c1 = 0;
			dfs(i, 0);

			if(bipar){
			    ans += max(c0, c1);
			}
    	}
    }
    cout << ans << ln;


    for(int i = 1; i <= n; i++){
    	ar[i].clear();
    	vis[i] = false;
    	colour[i] = -1;
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

