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

void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s = "$" + s;

    int ans = 0;

    for(int i = 1; i <= k / 2; i++) {

        vector<int> freq(26);
        int len = 0;

        for(int j = i; j <= n; j += k) {
            freq[s[j] - 'a']++;
            len++;
        }

        for(int j = k - i + 1; j <= n; j += k) {
            freq[s[j] - 'a']++;
            len++;
        }

        int mx = 0;

        for(int j = 0; j < 26; j++) {
            mx = max(mx, freq[j]);
        }

        ans += (len - mx);
    }
    if(k % 2) {

        vector<int> freq(26);
        int len = 0;

        int i = (k / 2) + 1;

        for(int j = i; j <= n; j += k) {
            freq[s[j] - 'a']++;
            len++;
        }

        int mx = 0;

        for(int j = 0; j < 26; j++) {
            mx = max(mx, freq[j]);
        }

        ans += (len - mx);
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

/**************

LEARNING IS FUN
SO ENJOY IT

***************/