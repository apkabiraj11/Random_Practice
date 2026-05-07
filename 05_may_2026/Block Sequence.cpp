#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 2e5 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

int n;
vector<int>ar(N);
int dp[N];
int find_ans(int i){

	if(i == n)
		return 0;
	if(i > n)
		return mod;
	if(dp[i] != -1)
		return dp[i];

	int ans = mod;
	if(i + ar[i] < n){
		ans = find_ans(i + ar[i] + 1);
		ans = min(ans, 1 + find_ans(i + 1));
	}
	else ans = min(ans, 1 + find_ans(i + 1));

	return dp[i] = ans;
}
void solve() {
    cin >> n;
    for(int i = 0;i < n; i++)
    	cin >> ar[i];

    memset(dp, -1, sizeof dp);
    ll get_ans = find_ans(0);
    cout << get_ans << ln;
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

