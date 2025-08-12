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
  int n, k; cin >> n >> k;

  char ar[n][k];
  for(int i=0; i<n; ++i) {
    for(int j=0; j<k; ++j) {
      cin >> ar[i][j];
    }
  }

  bool no[n] = {};
  for(int j=0; j<k; ++j) {
    for(int i=1; i<n; ++i) {
      if(ar[i][j] != ar[0][j]) no[i] = 1;
    }
  }

  int res = 0;
  for(int i=0; i<n; ++i) res += !no[i];

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

