#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  map<string, double> mp;
  while(n --) {
    string s; double x; cin >> s >> x; mp[s] = x;
  }

  int k; cin >> k;

  map<string, double> sa;

  double mx = 0;
  while(k--) {
    string s; int x; cin >> s >> x;
    if(mp.find(s) == mp.end()) continue ;
    sa[s] += mp[s]*x;
    mx = max(mx, sa[s]);
  }

  double total = 0;
  for(auto [a, b] : sa) total += b;
  if(total == 0) {
    cout << "No ice cream sales";
    return 0;
  }

  cout << "Total ice cream sales: " << total << ln;
  cout << "Top sales: ";
  for(auto [a, b] : sa) {
    if(b == mx) cout << a << ' ';
  }

  return 0;
}

