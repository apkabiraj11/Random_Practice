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
  string s;
  cin >> s;
  int n = s.size();
  map<int,int>mp;
  int l = 0, r = 0;
  bool got = false;
  while(r < n){
    mp[s[r]]++;

    if(r - l + 1 == 26){
      int sum = mp.size();
      if(mp.count('?')){
        sum += (mp['?'] - 1);
      }

      if(sum == 26){
        got = true;
        break;
      }

      mp[s[l]]--;
      if(mp[s[l]] == 0)
        mp.erase(s[l]);
      l++;
    }
    r++;
  }
  if(r - l + 1 == 26){
      int sum = mp.size();
      if(mp.count('?')){
        sum += (mp['?'] - 1);
      }

      if(sum == 26){
        got = true;
      }

      mp[s[l]]--;
      if(mp[s[l]] == 0)
        mp.erase(s[l]);
  }

  if(!got){
    cout << -1 << ln;
    return;
  }

  set<char>st;
  for(int i = l; i <= r; i++){
    if(s[i] != '?')
      st.insert(s[i]);
  }

  vector<char>not_avail;
  for(char c = 'A'; c <= 'Z'; c++){
    if(st.count(c) == 0){
      not_avail.push_back(c);
    }
  }
  for(int i = l; i <= r; i++){
    if(s[i] == '?'){
      s[i] = not_avail.back();
      not_avail.pop_back();
    }
  }

  for(int i = 0; i < n; i++){
    if(s[i] == '?')
      s[i] = 'A';
    cout << s[i];
  }
  




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

