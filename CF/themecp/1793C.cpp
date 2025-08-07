#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double
#define all(x) begin(x), end(x)
#define pb emplace_back

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

void solve() {
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x;

  int mn = 1, mx = n;
  int l = 0, r = n - 1;
  while(l < r) {
    if(v[l] == mn) l++, mn ++;
    else if(v[l] == mx) l++, mx --;
    else if(v[r] == mn) r--, mn ++;
    else if(v[r] == mx) r--, mx --;
    else break ;
  }

  if(l == r) cout << -1 << ln;
  else cout << l+1 << ' ' << r+1 << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

