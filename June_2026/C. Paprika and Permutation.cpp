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
    vector<int> ar(n);
    multiset<int>st;
    set<int>tt;
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    	if(ar[i] > n)
    		st.insert(ar[i]);
    	else {
    		if(tt.count(ar[i]))
    			st.insert(ar[i]);
    		else tt.insert(ar[i]);
    	}
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
    	int front = tt.count(i + 1);
    	if(front){
    		continue;
    	}
    	else {
    		auto it = st.upper_bound((i + 1) * 2);
    		if(it != st.end()){
    			cnt++;
    			st.erase(it);
    		}
    		else {
    			cout << -1 << ln;
    			return;
    		}
    	}
    }
    if(st.size()){
    	cout << -1 <<ln;
    }
    else cout << cnt << ln;
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

