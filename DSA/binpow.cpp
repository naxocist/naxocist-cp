#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int mod = 1e9 + 7;

ll binpow(ll x, ll y) {
  ll res = 1;
  for(;y;x=(x*x)%mod,y>>=1) if(y&1)res=(res*x)%mod;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  ll a, b; cin >> a >> b;
  cout << binpow(a, b);
  return 0;
}
