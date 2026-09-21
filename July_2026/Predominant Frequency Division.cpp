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
    vector<int>ar(n);
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    }
    vector<int>pref1(n), pref2(n);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] == 1){
            sum1++;
        }
        else sum1--;

        if(ar[i] < 3)
            sum2++;
        else sum2--;

        pref1[i] = sum1;
        pref2[i] = sum2;
    }

    int mn = mod;
    if(pref1[0] >= 0)
        mn = pref1[0];
    for(int i = 1; i < n - 1; i++){
        if(pref2[i] - mn >= 0){
            yes;
            return;
        }
        if(pref1[i] >= 0)
            mn = min(mn, pref2[i]);
    }
    no;

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

