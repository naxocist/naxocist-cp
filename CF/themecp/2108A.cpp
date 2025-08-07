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
  int res = 0;

  for(int i=1; i<=n; ++i) res += abs(n-i+1 - i);

  cout << res/2 + 1 << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

