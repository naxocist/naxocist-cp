#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

ll binpow(ll a, ll b, ll &k) {
  if(b == 0) return 1;

  ll r = binpow(a, b/2, k);
  if(b&1) return (((a*r)%k) * r)%k;
  return (r*r)%k;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  ll a, b, k; cin >> a >> b >> k;
  cout << binpow(a, b, k);
  return 0;
}

