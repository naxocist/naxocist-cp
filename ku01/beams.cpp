#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<int, ll>
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
const int N = 3e2 + 1;
int red[N],blue[N];

void solve() {
	
int n, m; cin >> n >> m;
	vector<int> a(n+1), b(m+1);
	int res = 0;
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=m; ++i) cin >> b[i];
	
	set<int> s;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i%2 == j%2) {
				if(a[i] == b[j] || a[i+1] == b[j+1]) {
					s.insert(a[i] == b[j] ? a[i] : a[i+1]);
					continue ;
				}	
			}else {
				if(a[i] == b[j+1] || a[i+1] == b[j]) {
					s.insert(a[i] == b[j+1] ? a[i] : a[i+1]);
					continue ;
				}
			}
			
			if(i%2 == j%2) {
				res += (b[j]<a[i]&&b[j+1]>a[i+1])||(b[j]>a[i]&&b[j+1]<a[i+1]);
			}else {
				res += (b[j]<a[i+1]&&b[j+1]>a[i]);
			}
		}
	}
	cout << res + s.size();
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
