#include <bits/stdc++.h>
using namespace std;
#define ln '\n'

void solve() {
    int n;
    cin >> n;
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    vector<int> st;
    vector<int> mn, mx;

    int xorr = 0;

    while(n--){
        b = (1LL * a * b + c) % m;

        if(b % 2){
            st.push_back(b);

            if(mn.empty() || b <= mn.back()) mn.push_back(b);
            if(mx.empty() || b >= mx.back()) mx.push_back(b);
        }
        else{
            if(!st.empty()){
                int val = st.back();
                st.pop_back();

                if(val == mn.back()) mn.pop_back();
                if(val == mx.back()) mx.pop_back();
            }
        }

        int beauty = 0;
        if(!st.empty()){
            beauty = mn.back() + mx.back();
        }

        xorr ^= beauty;
    }

    cout << xorr << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}