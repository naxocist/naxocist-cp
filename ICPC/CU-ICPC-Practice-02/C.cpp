#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; string s; cin >> s;

  map<string, int> mp;
  int cnt = 0;
  for(int i=0; i<n-1; ++i) {
    string t = s.substr(i,2);
    cnt = max(cnt, ++mp[t]);
  }

  for(auto [a, b] : mp) {
    if(cnt == b) cout << a, exit(0);
  }

  return 0;
}