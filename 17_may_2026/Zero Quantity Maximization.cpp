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

    vector<ll> ar(n), br(n);

    for(int i = 0; i < n; i++)
        cin >> ar[i];

    for(int i = 0; i < n; i++)
        cin >> br[i];

    vector<pair<ll,ll>> d;

    map<int,bool> have;

    for(int i = 0; i < n; i++){

        if(ar[i] != 0){

            ll num = -br[i];
            ll den = ar[i];

            ll g = __gcd(abs(num), abs(den));

            num /= g;
            den /= g;

            if(den < 0){
                den *= -1;
                num *= -1;
            }

            d.push_back({num, den});
        }

        else if(ar[i] == 0 && br[i] == 0)
            have[i] = true;
    }

    map<pair<ll,ll>, int> mp;

    for(auto x: d){
        mp[x]++;
    }

    int mx = 0;

    pair<ll,ll> expd;

    for(auto [x,y]: mp){

        if(y > mx){
            mx = y;
            expd = x;
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; i++){

        if(have.count(i))
            continue;

        if(ar[i] == 0)
            continue;

        ll num = -br[i];
        ll den = ar[i];

        ll g = __gcd(abs(num), abs(den));

        num /= g;
        den /= g;

        if(den < 0){
            den *= -1;
            num *= -1;
        }

        if(make_pair(num, den) == expd)
            cnt++;
    }

    cout << cnt + have.size() << ln;
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