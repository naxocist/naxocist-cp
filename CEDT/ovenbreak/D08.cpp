#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;

  vector<int> cnt(10);
  while(t--) {
    string s; cin >> s;
    for(char c : s) cnt[c-'0'] ++;
  }

  cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << x << ": " << cnt[x] << ln;
  }
  return 0;
}