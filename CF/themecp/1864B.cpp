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
  string s; cin >> s;

  if(k&1^1){
    sort(all(s)); cout << s << ln;
    return ;
  }

  string a, b;
  for(int i=0; i<n; i+=2) a += s[i];
  for(int i=1; i<n; i+=2) b += s[i];
  sort(all(a)); sort(all(b));

  int ai = 0, bi = 0;
  for(int i=0; i<n; ++i) {
    if(i&1) cout << b[bi++];
    else cout << a[ai++];
  }
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

