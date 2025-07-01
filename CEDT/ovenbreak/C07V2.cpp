#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 25;
ll ar[N][10];

ll pw(ll x, ll y) {
  ll res = 1;
  while(y>0) res *= x, y--;
  return res;
}

ll f(ll x) {
  if(x < 10) return 0;
  string s = to_string(x);
  int d = s.size();
  ll res = ar[d][s[0]-'0'-1];
  ll ex = 0;

  int i = 1;
  for(; i<d; ++i) {
    if(s[i] >= s[0]) {
      ex += pw(s[0]-'0', d-i);
      break ;
    } else {
      ex += pw(s[0]-'0', d-i-1)*(s[i]-'0');
    }
  }

  if(i == d) ex++;
  return res + ex;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;

  for(int i=2; i<N; ++i) {
    ar[i][0] = ar[i-1][9];
    for(int j=1; j<=9; ++j) {
      int k = i; ll r = 1;
      while(--k) r *= j;
      ar[i][j] = ar[i][j-1] + r;
    }
  }

  while(q--) {
    ll l, r; cin >> l >> r;
    // cout << f(r) << ' ' << f(l-1) << ln;
    cout << f(r) - f(l-1) << ln;
  }
  return 0;
}

