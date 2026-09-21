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

	ll C[55][55];

    C[0][0] = 1;

	for (int i = 1; i < 51; i++) {
	    C[i][0] = 1;
	    for (int j = 1; j <= i; j++) {
	        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
	    }
	}


	int n, m, t;
	cin >> n >> m >> t;

	ll ans = 0;
	for(int i = 4; i <= n; i++){
		int g = t - i;

		if(g >= 1 && g <= m){
			ll chose_boy = C[n][i];
			ll chose_girl = C[m][g];
			ans += (chose_boy * chose_girl);

		}
	}
	cout << ans << ln;
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

