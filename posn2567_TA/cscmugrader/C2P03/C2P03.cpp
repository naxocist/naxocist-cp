
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
#define p2(x) cout << #x << " = {" << x.f << ',' << x.s << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

void runcase() {
  int n, t; cin >> n >> t;
  vector<int> v(n); for(auto &x : v) cin >> x;
  while(t--) {
  	int c, pos, h; cin >> c;
  	if(c != 4) cin >> pos;
  	cin >> h;

  	if(h < 1) continue ; 
  	pos --;

  	if(c == 1) v[pos] += v[pos] < h;
  	else if(c == 2) v[pos] -= v[pos] >= h;
  	else if(c == 3) {
  		for(int j=max(0, pos-1); j<=pos+1 and j<n; ++j){
  			for(int i=h+1; i>=max(1,h-1); --i){
  					if(v[j] >= i) v[j]--;
  			}
  		}
  	}else for(auto &x : v) x -= x >= h;

  	for(auto x : v) cout << x << ' '; cout << ln;
  }
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) runcase();
  return 0;
}
