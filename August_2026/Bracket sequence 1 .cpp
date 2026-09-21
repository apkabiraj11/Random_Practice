#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x


int n;
ll fact[N], invFact[N];
ll bigmod(ll base, ll exp) {
    ll result = 1 % MOD;
    base %= MOD;
    while (exp) {
        if (exp & 1) 
        	result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[N - 1] = bigmod(fact[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}
ll ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
void solve() {
	cin >> n;
	if(n % 2){
		cout << 0 << ln;
		return;
	}

	ll ans = bigmod(n / 2 + 1, MOD - 2) * ncr(n , n / 2) % MOD;
	cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

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

