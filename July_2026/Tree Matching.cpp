#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
bool matched[N];
int ans = 0;

void dfs(int v, int p) {

    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
    }

    if (p != 0 && !matched[v] && !matched[p]) {
        matched[v] = matched[p] = true;
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans << '\n';
}