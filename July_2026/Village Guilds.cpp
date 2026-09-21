#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define endl "\n"

const int N = 2e5 + 7;
vector<int> tree[N];
ll ans;

int dfs(int u) {
    if (tree[u].empty()) return 1;
    vector<int> heights;
    for (auto v: tree[u]) {
        heights.push_back(dfs(v));
    }
    sort(heights.begin(), heights.end());
    if ((int)heights.size() > 1) ans += heights[(int)heights.size() - 2];
    return 1 + heights.back();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	int test = 1;
	cin >> test;

	while(test--){
        int n;  cin >> n;
        for (int i = 2; i <= n; i++) {
            int x;  cin >> x;
            tree[x].push_back(i);
        }
        dfs(1);
        cout << n + ans << '\n';

        ans = 0;
        for (int i = 1; i <= n; i++) tree[i].clear();
    }

	return 0;
}