#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 2005;
vector<int>ar(N), pref(N);
int xorr(int l, int r){
    return pref[r] ^ pref[l-1];
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    // pref[0] = 0;
    for(int i = 1; i <= n ;i++){
        pref[i] = pref[i-1] ^ ar[i];
    }
    for(int i = 1; i < n; i++){
        if(xorr(1, i) == xorr(i+1, n)){
            yes;
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j < n; j++){
            if(xorr(1,i) == xorr(i+1, j) && xorr(i+1, j) == xorr(j+1, n)){
                yes;
                return;
            }
        }
    }
    no;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    //int casee = 1;
    while(t--) {
        //cout<<"Case "<<casee<<" :";

        solve();

        // casee++;
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT 

***************/

