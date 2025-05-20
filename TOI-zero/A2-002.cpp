#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) x.begin(), x.end()
#define pb emplace_back

using pll = pair<ll, ll>;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pll> v(n); for(auto &[a, b] : v) cin >> a >> b;
  sort(all(v));
  unordered_map<ll,ll> uma, umb;

  ll res = 0;
  for(auto [a, b] : v){
  	if(uma.find(a+b) != uma.end()) res = max(res, a-uma[a+b]), uma[a+b] = min(uma[a+b], a);
  	else uma[a+b] = a;
  	if(umb.find(a-b) != umb.end()) res = max(res, a-umb[a-b]), umb[a-b] = min(umb[a-b], a);
  	else umb[a-b] = a;
  }
  cout << res;
  return 0;
}
