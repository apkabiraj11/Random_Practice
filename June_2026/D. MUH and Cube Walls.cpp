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

const int mod1 = 1000000007;
const int mod2 = 1000000009;

const int p1 = 911382323;
const int p2 = 972663749;

int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void precal_hashing() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(vector<int>&s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
struct hashing_struct {
	pair<int, int> pref[N];
	void build(vector<int>&s) {
	  int n = s.size();
	  for (int i = 0; i < n; i++) {
	    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
	    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
	    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
	    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
	  }
	}
	pair<int, int> get_hash(int i, int j) {
	  //assert(i <= j);
	  pair<int, int> hs({0, 0});
	  hs.first = pref[j].first;
	  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
	  hs.first = 1LL * hs.first * ipw[i].first % mod1;
	  hs.second = pref[j].second;
	  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
	  hs.second = 1LL * hs.second * ipw[i].second % mod2;
	  return hs;
	}
}A,B;
const long long OFFSET = 1000000001LL;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int>ar(n), br(w);
    for(int i = 0; i < n; i++)
    	cin >> ar[i];
    for(int i = 0; i < w; i++)
    	cin >> br[i];
    if(n < w){
    	cout << 0 << ln;
    	return;
    }

    // if(n == 1 && w == 1){
    // 	cout << 1 <<ln;
    // 	return;
    // }
    vector<int>dif_ar, dif_br;
    for(int i = 0; i < n - 1; i++){
    	dif_ar.push_back(ar[i+1] - ar[i] + OFFSET );
    	// cout << dif_ar[i] << " ";
    }
    // cout << ln;
    for(int i = 0; i < w - 1; i++){
    	dif_br.push_back(br[i + 1] - br[i] + OFFSET);
    	// cout << dif_br[i] << " ";
    }

    // cout << ln;

    A.build(dif_ar);
    B.build(dif_br);

    int l = 0, r = dif_br.size() - 1;
    auto br_hash = B.get_hash(l, r);
    int cnt = 0;
    while(r < n - 1){
    	if(A.get_hash(l, r) == br_hash){
    		cnt++;
    	}
    	l++, r++;
    }
    cout << cnt << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precal_hashing();
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