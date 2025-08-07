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
  int n, m, q; cin >> n >> m >> q;
  int a, b; cin >> a >> b;
  int x; cin >> x;
  if(a > b) swap(a, b);

  int res = 0;
  if(x < a) res = a-1;
  else if(x > b) res = n-b;
  else res = (b-a)/2;

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

