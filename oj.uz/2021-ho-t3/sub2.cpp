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

const int N = 23;
vector<int> h, revh;
int n, res = INT_MAX;
bool nw[N];
void f(int i) {
	if(i == n + 1) {

		vector<int> tar(n + 1);
		int base = 0;
		for(int i=1, j; i<=n;) {
			for(j=i+1; !nw[j] and j <= n+1; ++j);
			int sz = j - i;
			for(int k=1; k<=sz; ++k) tar[revh[sz-k+1 + base]] = k + base;
			base += sz;
			i = j;
		}

		// pa(pos, n);

		if(tar == revh) return ;

		int mv = 0;
		for(int i=1; i<=n; ++i) {
      for(int j=i+1; j<=n; ++j) {
				mv += tar[i] > tar[j];
      }
    }
		res = min(res, mv);
		return ;
	}

	nw[i] = true;
	f(i + 1);
	nw[i] = false;
	f(i + 1);
}
void solve() {
	cin >> n; h.resize(n + 1), revh.resize(n + 1);
  for(int i=1; i<=n; ++i) {
    cin >> h[i]; revh[h[i]] = i;
  }

	nw[1] = nw[n + 1] = true;
	f(2);
	cout << res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
