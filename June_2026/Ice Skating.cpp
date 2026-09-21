//https://codeforces.com/problemset/problem/217/A

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
int ar[1002][1002];
bool vis[1002][1002];
int n;
void dfs(int i, int j){
    vis[i][j] = true;

    for(int col = 1; col <= 1000; col++){
        if(ar[i][col] && !vis[i][col]){
            dfs(i, col);
        }
    }

    for(int row = 1; row <= 1000; row++){
        if(ar[row][j] && !vis[row][j]){
            dfs(row, j);
        }
    }
}
void solve() {
    cin >> n;
   	for(int i = 0; i < n; i++){
   		int u, v;
   		cin >> u >> v;
   		ar[u][v] = 1;
   	}

   	memset(vis, false, sizeof vis);

   	int ans = 0;
   	for(int i = 1; i <= 1000; i++){
   		for(int j = 1; j <= 1000; j++){
   			if(ar[i][j] && !vis[i][j]){
   				dfs(i, j);
   				ans++;
   			}
   		}
   	}
   	cout << ans - 1 << ln;
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

