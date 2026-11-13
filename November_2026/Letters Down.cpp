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

    string s;
    cin >> s;

    int l = 0, r = n - 1;
    vector<pair<char,char>> v;

    while(l < r) {
        if(s[l] != s[r]) {
            if(s[l] < s[r]) {
                v.push_back({s[l], s[r]});
            }
            else {
                v.push_back({s[r], s[l]});
            }
        }
        l++, r--;
    }

    sort(v.begin(), v.end());

    ll ans = 0;

    if(!v.empty()) {
        char first = v[0].first;
        char last = v[0].second;

        for(int i = 1; i < v.size(); i++) {
            if(last > v[i].first) {
                last = max(last, v[i].second);
            }
            else {
                ans += last - first;

                first = v[i].first;
                last = v[i].second;
            }
        }

        ans += last - first;
    }

    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/***************

LEARNING IS FUN
 SO ENJOY IT

***************/