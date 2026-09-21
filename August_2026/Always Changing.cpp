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

    vector<int> zero, one;

    int last = s[0] - '0';
    int cnt = 0;

    for(auto c : s) {
        if(c - '0' == last) {
            cnt++;
        }
        else {
            if(last == 0)
                zero.push_back(cnt);
            else
                one.push_back(cnt);

            last = c - '0';
            cnt = 1;
        }
    }


    if(last == 0)
        zero.push_back(cnt);
    else
        one.push_back(cnt);

    int onesum = 0;
    for(auto x : one)
        onesum += (x - 1);

    int zerosum = 0;
    for(auto x : zero)
        zerosum += (x - 1);

    auto check = [&](int a, int b){

        int tempone = onesum;
        int tempzero = zerosum;

        if(a == 0 && b == 0){
            int dif = abs(tempone - tempzero);
            return (dif <= 1) ? (tempone + tempzero) : -1;
        }
        else if(a == 0 && b == 1){
            if(s.back() - '0' == 1)
                tempone++;
            else tempzero++;

            int dif = abs(tempone - tempzero);
            return (dif <= 1) ? (tempone + tempzero) : -1;
        }
        else if(a == 1 && b == 0){
            if(s.front() - '0' == 1)
                tempone++;
            else tempzero++;

            int dif = abs(tempone - tempzero);
            return (dif <= 1) ? (tempone + tempzero) : -1;
        }
        else {
            if(s.back() - '0' == 1)
                tempone++;
            else tempzero++;

            if(s.front() - '0' == 1)
                tempone++;
            else tempzero++;

            int dif = abs(tempone - tempzero);
            return (dif <= 1) ? (tempone + tempzero) : -1;
        }


    };
    int ans = -1;
    ans = check(0, 0);
    if(ans != -1){
        cout << ans << ln;
        return;
    }
    ans = check(0, 1);
    if(ans != -1){
        cout << ans << ln;
        return;
    }
    ans = check(1, 0);
    if(ans != -1){
        cout << ans << ln;
        return;
    }
    ans = check(1, 1);
    if(ans != -1){
        cout << ans << ln;
        return;
    }
    cout << -1 << ln;
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

