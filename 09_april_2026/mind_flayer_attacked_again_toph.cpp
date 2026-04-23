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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>st(n);
    vector<ll>br(m);
    for(int i = 0; i < n; i++){
        cin >> st[i];
    }
    for(int i = 0; i < m; i++)
        cin >> br[i];

    sort(br.begin(),br.end());
    sort(st.begin(),st.end());

    vector<ll>tt;
    for(auto x : br){
        auto it = lower_bound(st.begin(),st.end(), x);
        ll  ag = 0;
        if(it != st.begin()){
            it--;
            ag = *it;
        }
        tt.push_back(ag + x);
    }
    
    for(int i = 1; i < m; i++){
        br[i] += br[i - 1];
    }

    ll ans = 0;
    for(auto x : st){
        auto it = upper_bound(br.begin(),br.end(), x) - br.begin();
        ans += it;
    }
    for(auto x : tt){
        auto it = upper_bound(br.begin(),br.end(), x) - br.begin();
        ans += (it * k);
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
