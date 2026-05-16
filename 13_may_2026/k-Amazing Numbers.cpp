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
    vector<pair<int,int>>ar;
    set<int>st;
    for(int i = 1; i <= n; i++){
    	int x;
    	cin >> x;
    	st.insert(x);
    	ar.push_back({x, i});
    }
    for(auto x : st){
    	ar.push_back({x, 0});
    	ar.push_back({x, n + 1});
    }
    sort(ar.begin(), ar.end());
    vector<int> ans(n + 5, mod);

    for(int i = 0; i < ar.size(); i++ ){
        int len = 0;
        int val = -1;
        int j;
        for(j = i; j < ar.size() - 1; j++){
            auto [x1, i1] = ar[j];
            auto [x2, i2] = ar[j + 1];
            if(x1 == x2){
                val = x1;
                len = max(len, abs(i1 - i2));
            }
            else {
                break;
            }
        }
        ans[len] = min(ans[len], val);
        i = j; 
    }
    for(int i = 1; i <= n; i++){
    	ans[i] = min(ans[i], ans[i - 1]);
    }
    for(int i = 1; i <= n; i++){
    	if(ans[i] == mod)
    		ans[i] = -1;
    	cout << ans[i] << " ";
    }
    cout << ln;
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

