#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  using pi = pair<int, int>;
  vector<pi> v(n); 
  for(int i=0; i<n; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  int k; cin >> k;
  int pv = -1;
  ll s = 0;
  while(k--) {
    if(pv != -1) {
      s += v[pv-1].second;
      cout << "T" << pv << ": " << v[pv-1].second << ln;
    }
    int x; cin >> x;
    if(pv != -1) cout << "L" << x << ": " << v[x-1].first << ln, s += v[x-1].first;
;
    pv = x;
  }

  cout << "Total : " << s;
  return 0;
}