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
    int n, a, b;
    cin >> n >> a >> b;
    if(a + b > n){
    	no;
    	return;
    }
    if((a == 0 || b == 0) && a + b > 0){
    	no;
    	return;
    }

    vector<int>ar(n + 1), br(n+1);
    for(int i = 1; i <= n; i++){
    	ar[i] = i;
    	br[i] = i;
    }
    bool rev = false;
    if(a < b) swap(a, b), rev = true;

    vector<int>temp;
    for(int i = n; i >= 1; i--){

    	temp.push_back(br[i]);
    	br[i] = -1;

    	if((int)temp.size() == b){
    		int k = n;
    		for(int j = i - 1; j >= 1; j--){
    			swap(br[k], br[j]);
    			k--;
    			a--;
    			if(a == 0){
    				break;
    			}
    		}
    		break;
    	}
    }
    for(int i = 1; i <= n; i++){
    	if(br[i] == -1){
    		br[i] = temp.back();
    		temp.pop_back();
    	}
    }

    yes;
    if(rev)
    	swap(ar, br);

    for(int i = 1; i <= n; i++){
    	cout << ar[i] << " ";
    }
    cout << ln;
    for(int i = 1; i <= n; i++){
    	cout << br[i] << " ";
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

