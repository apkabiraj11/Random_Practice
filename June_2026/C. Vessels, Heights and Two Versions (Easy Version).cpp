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
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    }
    int mxid = max_element(ar.begin(),ar.end()) - ar.begin();
    int mx = ar[mxid];
    for(int i = 0; i < n; i++){
    	int temp = -1;

        for(int j = i; j < i + n; j++){
            if(ar[j % n] == mx){
                temp = j % n;
            }
        }

    	if(temp != -1)
    		mxid = temp;

    	vector<int>ans(n);
    	ans[i] = 0;
    	int last = 0;
        
        for(int j = i; j < i + n; j++){
            if(ans[j % n] > ar[j % n]){
                ans[(j + 1) % n] = ans[j % n];
            }
            else {
                ans[(j + 1) % n] = ar[j % n];
            }
            if((j % n) + 1 == mxid){
                break;
            }
        }

        for(int j = i - 1; ;j--){
            if(j < 0)
                j = n - 1;
            if(j == mxid)
                break;
            last = max(last, ar[j]);
            ans[j] = last;
        }
        
        ans[i] = 0;
        ll sum = 0;
        for(int j = 0; j < n; j++){
            sum += ans[j];
            // cout << ans[j] << " ";
        }
        // cout<< ln;
        cout << sum << " ";

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

