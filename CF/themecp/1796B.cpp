#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.first << ',' << x.second << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa1(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

void solve() {
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();

  if(a[0] == b[0]) {
    cout << "YES\n";
    cout << a[0] << "*\n";
    return ;
  }

  if(a[n-1] == b[m-1]) {
    cout << "YES\n";
    cout << "*" << a[n-1] << "\n";
    return ;
  }

  for(int i=0; i<n-1; ++i) {
    for(int j=0; j<m-1; ++j) {
      if(a.substr(i,2) == b.substr(j,2)) {
        cout << "YES\n";
        cout << "*" << a.substr(i,2) << "*\n";
        return ;
      }
    }
  }

  cout << "NO\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC;
  while(TC--) solve();
  return 0;
}
