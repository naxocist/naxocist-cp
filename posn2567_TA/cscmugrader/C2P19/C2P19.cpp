#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)
#define pb emplace_back
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.first << ',' << x.second << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

map<string, int> um = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

void runcase() {
	int n; cin >> n;
	using T = tuple<int, int, int, string, string>;
	vector<T> v; 
	for(int i=0; i<n; ++i) {
		int d, y; string m, name; cin >> d >> m >> y >> name;
		v.pb(d, um[m], y, name, m);
	}


	int q; cin >> q;
	while(q--) {
		int s, d, y; string m; cin >> s >> d >> m >> y;

		using T2 = tuple<int, int, int>;
		T2 tar = T2(d, um[m], y);
		int l = 0, r = n-1;
		string res = "";
		while(l < r) {
			int m = l + (r-l)/2;
			if(v[m] == )
		}

		if(res == "") printf("key: %d/%s/%d not found\n",d,m.c_str(),y);
		else printf("key: %d/%s/%d found %s",d,m.c_str(),y,res);
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
