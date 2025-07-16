#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back
#define sz(x) x.size()
const int mod = 1e9 + 7;

 
inline int f(int a) {
  a %= mod;
  if(a < 0) a += mod;
  return a;
}

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return 1ll*a*b % mod; }

inline int binpow(int a, int b) {
  int res = 1;
  while(b) {
    if(b&1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int _div(int a, int b) { return mul(a, binpow(b,mod-2)); }


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;

  vector<int> y;
  int s = 0;
  y.pb(0);
  for(int i=1; i<=k+1; ++i) {
    s = add(s, binpow(i, k));
    y.pb(s);
  }

  if(n < sz(y)) cout << y[n], exit(0);

  int t = 1;
  for(int i=1; i<sz(y); ++i) {
    t = mul(t, _div(f(n-i), f(-i)));
  }

  int res = 0;
  for(int i=0; i<sz(y); ++i) {
    res = add(res, mul(y[i], t));
    t = mul(t, _div(f(n - i), f(n - (i + 1))));
    t = mul(t, _div(f(i - (sz(y) - 1)), f(i + 1)));
  }

  cout << res;
  return 0;
}
