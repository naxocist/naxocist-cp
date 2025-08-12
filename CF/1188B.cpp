#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

ll n, p, k;

ll binpow(ll x, ll y) {
  ll res = 1;
  for(;y;x=(x*x)%p,y>>=1) if(y&1)res=(res*x)%p;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> p >> k;

  map<ll, ll> mp;
  ll res = 0;

  for(int i=0; i<n; ++i){
    ll x; cin >> x; 
    ll t = (binpow(x,4) - (x*k)%p + p) % p;
    res += mp[t];
    mp[t] ++;
  }

  cout << res;
  return 0;
}
