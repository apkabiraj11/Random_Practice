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
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<vector<int>> mat(n, vector<int>(m));
	multiset<int> st;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			st.insert(mat[i][j]);
		}
	}

	// for(auto x : st)
	// 	cout << x << " ";
	vector<vector<ll>> mx(n, vector<ll>(m));

	for(int i = 0; i < n; i++){
		vector<int> temp;
		for(int j = 0; j < m; j++){
			mx[i][j] = *st.rbegin();
			temp.push_back(*st.rbegin());
			st.erase(prev(st.end()));
		}

		for(int j = 0; j < m; j++){
			st.insert(temp[j]);
		}
		for(int j = 0; j < m; j++){
			st.erase(st.find(mat[i][j]));
		}
	}


	int ans = m;
	for(int i = 0; i < n; i++){
		ll temp = 0;
		for(int j = 0; j < m; j++){
			temp += mx[i][j];
			if(temp >= ar[i]){
				ans = min(ans, j + 1);
			}
		}

	}
	cout << ans << ln;

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

