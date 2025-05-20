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

#define INF 2e9
const int N = 300;
int d[N][N];
bool ok[N][N];
void solve() {
  int n,m;cin>>n>>m;
  for(int i=0;i<n;++i){
  	for(int j=0;j<n;++j)d[i][j]=INF;
  	d[i][i]=0;
  }
  while(m--){
  	int u,v;cin>>u>>v;u--,v--;
  	d[u][v]=d[v][u]=ok[u][v]=ok[v][u]=1;
  }
  for(int k=0;k<n;++k) for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(i!=j and d[i][k]!=INF and d[k][j]!=INF) d[i][j]=min(d[i][j],d[i][k]+d[k][j]); 
  	
  int mn=d[0][n-1]-1,res=0;
  for(int i=0;i<n;++i)
  	for(int j=i+1;j<n;++j){
  		if(ok[i][j])continue;
  		if(d[0][i]+d[j][n-1]<mn or d[0][j]+d[i][n-1]<mn)res++;
  	}
  
  cout<<res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
