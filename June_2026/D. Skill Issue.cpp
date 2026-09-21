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
    int n, m;
    cin >> n >> m;
    
    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<int>> ar(n + 2);
    for(int i = 1; i <= m ;i++){
    	int u, v;
    	cin >> u >> v;
    	ar[u].push_back(v);
    	ar[v].push_back(u);
    }    

    vector<int> color(n + 2, -1), vis(n + 2), dis(n + 2);
    queue<int>q;
    vis[c] = 1;
    dis[c] = 0;
    q.push(c);
    while(!q.empty()){
    	int par = q.front();
    	q.pop();

    	color[par] = 1;

    	for(auto child : ar[par]){
    		if(!vis[child]){
    			vis[child] = 1;
    			dis[child] = dis[par] + 1;
    			q.push(child);
    		}
    	}
    }


    bool interconnect = false;
    if(!vis[a]){
    	q.push(a);
    	vis[a] = 1;
    	while(!q.empty()){
    		int par = q.front();
    		q.pop();
    		if(par == b){
    			interconnect = true;
    			break;
    		}
    		for(auto child : ar[par]){
    			if(!vis[child]){
    				q.push(child);
    				vis[child] = 1;
    			}
    		}
    	}
    }


    if(color[a] == -1 && color[b] == -1){
    	if(!interconnect)
    		cout << "Tie" << ln;
    	else cout << "Alice" <<ln;
    }
    else if(color[a] == -1 && color[b] != -1){
    	if(dis[b] >= 2){
    		cout << "Alice" << ln;
    	}
    	else if(dis[b] == 1){
    		cout << "Tie" << ln;
    	}
    	else cout << "Bob" << ln;
    }
    else if(color[a] != -1 && color[b] == -1){
    	cout << "Alice" << ln;
    }
    else {
    	if(dis[a] < dis[b]){
    		cout << "Alice" << ln;
    	}
    	else if(dis[a] > dis[b]){
    		cout << "Bob" <<ln;
    	}
    	else cout << "Tie" << ln;
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