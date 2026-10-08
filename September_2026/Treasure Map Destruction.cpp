#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    vector<int> diff(n + 3);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(a[i] > 0) {
            int l = max(1, i - a[i] + 1);
            int r = min(n, i + a[i] - 1);

            diff[l]++;
            diff[r + 1]--;
        }
    }

    vector<bool> safe(n + 2);

    int cur = 0;

    for(int i = 1; i <= n; i++) {
        cur += diff[i];

        if(cur == 0)
            safe[i] = true;
    }

    bool ok = true;
    for(int i = 1; i <= n; i++) {
        if(a[i] < 0)
            continue;

        if(i - a[i] >= 1 && safe[i - a[i]]){
            continue;
        }
        if(i + a[i] <= n && safe[i + a[i]]){
        	continue;
        }

        ok = false;
        break;
    }

    if(!ok){
    	cout << -1 << ln;
    	return;
    }

    for(int i = 1; i <= n; i++)
        cout << (safe[i] ? '1' : '0');

    cout << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}