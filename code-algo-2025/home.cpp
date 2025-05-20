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

const int N = 1e2 + 1, mod = 1e9 + 7;
vector<int> adj[N];
map<vector<int>, vector<int>> mp;

void solve() {
  int n,k;cin>>n>>k;

  for(int i=0;i<k;++i){
  	int x;cin>>x;
  	vector<int> st;
  	while(x--){
  		int t;cin>>t;
  		adj[t].pb(i);
  		st.pb(t);
  	}
  	sort(all(st));
  	mp[st].pb(i);
  }

  vector<int> dp(k,1);
  for(int i=1;i<n;++i){
  	vector<int> dp2(k);
  	for(auto &[a,b]:mp){
  		int t=0;
  		for(auto &x:a)t+=dp[x],t%=mod;
  		for(auto &y:b)dp2[y]=t;
  	}
  	dp=dp2;
  }
  int res=0;
  for(int i=0;i<k;++i)res+=dp[i],res%=mod;
  cout<<res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
