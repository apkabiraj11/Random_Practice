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

ll lcm(int a, int b){
	return 1LL*a*b / __gcd(a, b);
}
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    ll common = m / (lcm(lcm(a, b), c));
   
    // alice
    ll duijon = m / lcm(a, b) + m / lcm(a, c) - 2 * common;
    ll alice = 2 * common + 3 * duijon + 6 * (m / a - (duijon + common));

    //bob
    ll duijon1 = m / lcm(a, b) + m / lcm(b, c) - 2 * common;
    ll bob = 2 * common + 3 * duijon1 + 6 * (m / b - (duijon1 + common));
    
    //carot
    ll duijon2 = m / lcm(a, c) + m / lcm(b, c) - 2 * common;
    ll carot = 2 * common + 3 * duijon2 + 6 * (m / c - (duijon2 + common));
    
    cout << alice << " " << bob << " " << carot << ln;

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

