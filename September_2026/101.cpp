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
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> ar[i];

    vector<int>pref(n + 1);
    for(int i = 1; i <= n; i++){
    	pref[i] = pref[i - 1] + (ar[i] == 1);
    }

    int l = -1, r = -1;
    int ans = 0;
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
    	if(ar[i] != 0){
    		int minus_id = mp[-1];
    		int one_id = mp[1];

    		if(minus_id){
    			int cnt = pref[i - 1] - pref[minus_id];
    			if(cnt == 0){
    				if(i - minus_id + 1 > ans){
    					ans = i - minus_id + 1;
    					l = minus_id;
    					r = i;
    				}
    			}
    		}
    		if(one_id){
    			int cnt = pref[i - 1] - pref[one_id];
    			if(cnt == 0){
    				if(i - one_id + 1 > ans){
    					ans = i - one_id + 1;
    					l = one_id;
    					r = i;
    				}
    			}
    			
    		}
    	}

    	mp[ar[i]] = i;
    }


	int l1 = -1, r1 = -1, last = -1;

	for(int i = 1; i <= n; i++) {
	    if(ar[i] == -1) {
	        if(last == -1) last = i;
	        else if(i - last > r1 - l1)
	            l1 = last, r1 = i;
	    }
	    else if(ar[i] != 0) {
	        last = -1;
	    }
	}

	if(r1 - l1 + 1 > ans){
		l = l1, r = r1;
	}

    if(l == -1 && r == -1){
    	for(int i = 1; i <= n; i++){
    		if(ar[i] == -1)
    			cout << 1 << " ";
    		else cout << ar[i] << " ";
    	}
    	cout << ln;
    	return;
    }

    ar[l] = 1, ar[r] = 1;
    for(int i = l + 1; i <= r - 1; i++){
    	ar[i] = 0;
    }


    for(int i = 1; i <= n; i++){
    	if(i < l && ar[i] == -1)
    		ar[i] = 1;
    	
    	else if(i > r && ar[i] == -1)
    		ar[i] = 1;
    }


    for(int i = 1; i <= n; i++)
    	cout << ar[i] << " ";

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

