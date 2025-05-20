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
#define pa1(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

const int N = 23;

void solve() {
	int n; cin >> n;
	vector<int> h(n), revh(n);
  for(int i=0; i<n; ++i) {
    cin >> h[i]; h[i] --;
		revh[h[i]] = i;
  }

	vector<int> dp(n);
	for(int i=1; i<n; ++i) {
		dp[i] = INT_MAX;
		for(int j=0; j<=i; ++j) {
			// force interval [j, i]
			vector<int> tar(n, -1);

			int pos = 0;
			for(int c=0; c<j; ++c) tar[revh[c]] = revh[c], pos++;
			for(int c=i; c>=j; --c) tar[revh[c]] = 10000 + pos++;

			int cost = 0;
			for(int a=0; a<n; ++a) {
				for(int b=a+1; b<n; ++b) {
					if(tar[a] == -1 || tar[b] == -1) continue ;
					cost += tar[a] > tar[b];
				}
			}
			// pv(tar); cout << cost << ln;
			dp[i] = min(dp[i], (j ? dp[j-1] : 0) + cost);
		}
		// cout << "---\n";
	}

	// pv(dp);

	cout << dp[n-1];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
