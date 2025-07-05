#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

ll binpow(ll x, ll y, ll mod) {
  ll res = 1;
  for(;y;x=(x*x)%mod,y>>=1) if(y&1)res=(res*x)%mod;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  while(n--) {
    ll N, x, y, k, p; cin >> N >> x >> y >> k >> p;

    // ll sj = 0;
    // for(ll i=1; i<=N; ++i) {
    //   sj += i*(i+1)/2; sj%=k;
    // }
    __int128 sj = N*(N+1)*(N+2)/6;
    sj %= k;

    // (x + 2*x*y)j % k
    ll a = x + (2*x*y)%k; a%=k;
    a *= sj, a%=k;

    // (kxy)^(i-j) % k
    // ll bb = 0;
    ll b = N%k;
    // for(int i=1; i<=N; ++i) {
    //   for(int j=1; j<=i; ++j) b += binpow(bb,abs(i-j),k), b%=k;
    // }


    // yj % k
    ll c = sj*y; c%=k;

    // OwO
    ll d = 0;
    if(p) {
      d ++;
      if(N >= 2) d += 2;
    } 
    // if(p)
    // for(int i=1; i<=N; ++i) {
    //   for(int j=1; j<=i; ++j) {
    //     d += ((i+j)%2?-1:1)*Cnr(i,j,k); d%=k;
    //     d*=binpow(j,2,k); d%=k;
    //   }
    // }

    // sum i^3
    ll e = N*(N+1)/2; e%=k;
    e = binpow(e,2,k);


    a += b, a %= k;
    a += c, a %= k;
    a += d, a %= k;
    a += e, a %= k;
    cout << a << ln;
  }
  return 0;
}