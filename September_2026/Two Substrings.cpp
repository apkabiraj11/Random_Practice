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
    string s;
    cin >> s;


    for(int i = 0; i < s.size() - 1; i++){
    	if(s[i] == 'A' && s[i + 1] == 'B'){
    		
    		for(int j = 0; j < s.size() - 1; j++){
				if(j < i - 1 || j > i + 1){
					if(s[j] == 'B' && s[j + 1] == 'A'){
						yes;
						return;
					}
				}  			
    		}
    		break;
    	}
    }
    
    no;

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

