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
    int n;
    cin >> n;
    vector<int> ar[n + 2];
    vector<pair<int,int>> edgelist;
    vector<int>deg(n + 2);
    for(int i = 1; i < n; i++){
    	int u,v;
    	cin >> u >> v;
    	ar[u].push_back(v);
    	ar[v].push_back(u);
    	edgelist.push_back({u,v});
    	deg[u]++;
    	deg[v]++;
    }

    vector<pair<int,int>> mn;
    for(int i = 1; i <= n; i++){
    	if(deg[i] > 0)
    		mn.push_back({deg[i], i});
    }
    sort(mn.begin(),mn.end());
    map<pair<int,int>, int> mp;
    int ans = 1;
    for(int i = 0; i < n; i++){
    	auto [d, node] = mn[i];
    	for(auto x : ar[node]){
    		if(mp[{x, node}])
    			continue;
    		mp[{x, node}] = ans;
    		mp[{node, x}] = ans;
    		ans++;
    	}
    }


    for(auto [u, v] : edgelist){
    	cout << mp[{u, v}] - 1 << ln;
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

