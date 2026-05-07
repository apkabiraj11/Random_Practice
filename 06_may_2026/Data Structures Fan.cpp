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
    vector<int>ar(n + 2);
    for(int i = 1;i <= n; i++){
    	cin >> ar[i];
    }
    string s;
    cin >> s;


    int xorr1 = 0;
    int xorr0 = 0;
    for(int i = 1; i <= n; i++){
    	if(s[i - 1] == '0')
    		xorr0 ^= ar[i];
    	else xorr1 ^= ar[i];

    	ar[i] ^= ar[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
    	int type;
    	cin >> type;
    	if(type == 1){
    		int l, r;
    		cin >> l >> r;
    		xorr1 ^= ar[r] ^ ar[l - 1];
    		xorr0 ^= ar[r] ^ ar[l - 1];
    	}
    	else {
    		int g;
    		cin >> g;
    		if(g == 1){
    			cout << xorr1 << " ";
    		}
    		else cout << xorr0 << " ";
    	}

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

