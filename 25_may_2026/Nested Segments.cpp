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

bool cmp(vector<int> &a, vector<int>&b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ar;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        ar.push_back({l, r, i});
    }
    sort(ar.begin(),ar.end(), cmp);
    int last = -1;
    ll mx = INT_MIN;
    for(auto &x : ar){
        if(mx == INT_MIN){
            mx = x[1];
            last = x[2];
            continue;
        }
        else {
            if(mx >= x[1]){
                cout << x[2]<< " " << last << ln;
                return;
            }
        }
        if(mx < x[1]){
            mx = x[1];
            last = x[2];
        }
    }
  
    cout << -1 << " " << -1 << ln;

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

