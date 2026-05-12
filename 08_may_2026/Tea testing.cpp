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
    vector<ll>ar(n + 2),br(n + 2), dif(n + 2), extra(n + 2);
    for(int i = 1; i <= n; i++)
    	cin >> ar[i];
    for(int i = 1; i <= n; i++)
    	cin >> br[i];

    vector<ll>pref(n + 2);
    for(int i = 1; i <= n; i++){
    	pref[i] = pref[i - 1] + br[i];
    }

    for(int i = 1; i <= n; i++){
    	int l = i, r = n;
    	int ans = i - 1;
    	while(l <= r){
    		int mid = (l + r) / 2;
    		if(pref[mid] - pref[i - 1] <= ar[i]){
    			ans= mid;
    			l = mid + 1;
    		}
    		else r = mid - 1;
    	}
    	if(ans >= i){
		    dif[i]++;
		    dif[ans + 1]--;
		}
		extra[ans + 1] += ar[i] - (pref[ans] - pref[i - 1]);
    }

    for(int i = 1; i <= n; i++){
    	dif[i] += dif[i - 1];
    }

    for(int i = 1; i <= n; i++){
    	ll ans = 1LL*dif[i]*br[i] + extra[i];
    	cout << ans << " ";
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

