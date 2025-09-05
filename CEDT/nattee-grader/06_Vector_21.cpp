#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  s += '$';

  vector<string> v;
  for(int i=0; i<s.size(); ++i) {
    v.pb(s);
    rotate(s.begin(), s.begin() + 1, s.end());
  }
  sort(all(v));

  string res;
  for(auto x : v) res += x.back();
  cout << res;
  return 0;
}

