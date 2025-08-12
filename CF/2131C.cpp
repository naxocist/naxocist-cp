#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    vector<int> s(n), t(n);
    for(auto &x : s) cin >> x;
    for(auto &x : t) cin >> x;

    map<int, int> mp;
    for(auto x : s) {
      int a = x%k, b = (-x%k + k)%k;
      mp[a] ++; mp[b] ++;
    }

    map<int, int> mp2;
    for(auto y : t) {
      int a = y%k, b = (-y%k + k)%k;
      mp2[a] ++; mp2[b] ++;
    }

    if(mp == mp2) cout << "yes";
    else cout << "no";
    cout << ln;

  }
  return 0;
}
