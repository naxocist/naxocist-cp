
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
#define px : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

void runcase() {
	int n, m; cin >> n >> m;
	priority_queue<int> pq, pq2;
	for(int i=0; i<n; ++i) {
		int x; cin >> x; pq.emplace(x);
	}
	
	for(int i=0; i<m; ++i) {
		int x; cin >> x; pq2.emplace(x);
	}

	int ans = 0;
	while(!pq2.empty()) {
		int x = pq2.top(); 
		if(pq.empty()) break ;
		if(x > pq.top()) ans += x, pq.pop(), pq2.pop();
		else pq.pop();
	}
	cout << ans;
	return ;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int TC = 1;
	// cin >> TC; 
	while(TC--) runcase();
	return 0;
}
