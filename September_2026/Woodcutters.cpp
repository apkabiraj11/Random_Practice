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
    vector<pair<int,int>> ar(n);

    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        ar[i] = {x, h};
    }

    sort(ar.begin(), ar.end());

    if(n == 1){
        cout << 1 << ln;
        return;
    }

    int ans = 1;
    int l = ar[0].first;

    for(int i = 1; i < n; i++){
        auto [xi, hi] = ar[i];

        if(xi - hi > l){
            ans++;
            l = xi;
        }
        else{
            if(i < n - 1){
                auto [xj, hj] = ar[i + 1];

                if(xi + hi < xj){
                    ans++;
                    l = xi + hi;
                }
                else{
                    l = xi;
                }
            }
            else{
                ans++;
                l = xi + hi;
            }
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

