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
int a[4][4];

void solve() {
  vector<string> nm(4); for(auto &x:nm)cin>>x;
  for(int i=0;i<4;++i)for(int j=0;j<4;++j)cin>>a[i][j];
  using T=tuple<int,int,int,string>;
  vector<T> v;
  for(int i=0;i<4;++i){
  	int s,g,rg;s=g=rg=0;
  	for(int j=0;j<4;++j){
  		if(i==j)continue;
  		if(a[i][j]>a[j][i])s+=3;
  		else if(a[i][j]==a[j][i])s++;
  		g+=a[i][j],rg+=a[j][i];
  	}
  	v.pb(s,g-rg,g,nm[i]);
  }
  sort(all(v),greater<T>());
  for(auto [s,_,__,t]:v) cout<<t<<' '<<s<<'\n';
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
