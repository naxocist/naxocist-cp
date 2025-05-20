
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

int cnt[21][21];
void runcase() {
	int n; cin >> n;
	int a, b, aa, bb; cin >> a >> b >> aa >> bb;

	memset(cnt, -1, sizeof cnt);
	using pi = pair<int, int>;
	queue<pi> q; q.emplace(a, b);
	cnt[a][b] = 0;
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		if(x == aa and y == bb) {
			cout << cnt[x][y];
			return ;
		}
		int tx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
		int ty[] = {-2, -1, 1, 2, 2, 1, -1, -2};
		for(int i=0; i<8; ++i) {
			int nx = x + tx[i], ny = y + ty[i];
			if(nx < 0 or nx >= n or ny < 0 or ny >= n or cnt[nx][ny] != -1) continue ;
			cnt[nx][ny] = cnt[x][y] + 1;
			q.emplace(nx, ny);
		}
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
