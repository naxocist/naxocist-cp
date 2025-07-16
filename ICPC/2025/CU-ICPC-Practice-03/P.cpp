#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

ll n,l,r;
void f(ll x, ll s, ll t) {

  if(t + s >= l) {
    ll a = x, b = x + (l-t+1)/2;

    if(b == n + 1) a = 1;

    for(ll i=l; i<=r; ++i) {
      if(i%2) cout << a;
      else {
        cout << b;
        if(b == n) {
          a ++;
          b = a + 1;

          if(b == n + 1) a = 1;
          // cout << "B: " << b << ln;
        }else b++;
      }

      cout << ' ';
    }
    return ;
  }

  f(x+1,s-2 > 0 ? s-2 : 1,t+s);
}

void solve() {
  cin >> n >> l >> r;

  f(1,2*(n-1),0);
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
