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
    vector<int>ar(n);
    map<int,int>mp;
    for(int i = 0; i < n; i++){
    	cin>> ar[i];
    	mp[ar[i]]++;
    }

    vector<int>left;
    int cnt = 0;
    for(auto [x,y] : mp){
    	if(y){
    		left.push_back(x);
    		cnt++;
    		mp[x]--;
    	}
    }
    vector<int>right;
    for(auto [x,y] : mp){
    	if(y){
    		right.push_back(x);
    		cnt++;
    		mp[x]--;
    	}
    }
    reverse(right.begin(),right.end());
    vector<int>mid;
    for(auto [x,y] : mp){
    	for(int i = 0; i < y; i++){
    		mid.push_back(x);
    	}
    }
    cout << cnt << ln;
    for(auto x : left)
    	cout << x << " ";
    for(auto x : mid)
    	cout << x << " ";
    for(auto x : right)
    	cout << x << " ";
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

