#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)
#define pb emplace_back
#define dump(a) while(a.size())a.pop();
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.first << ',' << x.second << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

const int N = 5e3 + 3;
void solve() {
	int n; cin >> n;
  vector<int> v(n), rev(n + 1);
  for(int i=0; i<n; ++i) {
    cin >> v[i]; rev[v[i]] = i;
  }

  // pv(v);
  int res = INT_MAX;
  vector<int> t(n); iota(all(t), 1);
  do {
    bool ok = true;

    vector<int> tar(n + 1);
    for(int i=0; i<n; ++i) {
      if(i and t[i-1] >= t[i] + 2) ok = false;
      tar[rev[t[i]]] = i;
    }

    if(!ok or t == v) continue ;

    int mv = 0;
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        mv += tar[i] > tar[j];
      }
    }
    res = min(res, mv);
  }while(next_permutation(all(t)));

  cout << res ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
