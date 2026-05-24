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
    vector<tuple<int,int,int>> ar;
    for(int i = 1; i <=n;i++){
    	int li, ri;
    	cin >> li >> ri;
    	ar.push_back({li, ri, i});
    }
    sort(ar.begin(),ar.end());
    vector<int>ans(n + 1);
    auto [x,y,z] = ar[0];
    int mx = y;
    // cout << mx << " ";
    for(int i = 0; i < n; i++){
    	auto [li, ri, id] = ar[i];
    	if(li > mx){
    		ans[id] = 2; 
    	}
    	else 
    		ans[id] = 1;
    	mx = max(mx, ri);
    }

    if(count(ans.begin(),ans.end(), 2) == 0){
    	cout << -1 << ln;
    }
    else {
    	for(int i = 1; i <= n;i++)
    		cout << ans[i] << " ";
    	cout<< ln;
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