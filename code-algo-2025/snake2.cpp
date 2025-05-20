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

const int N=8e3+3, INF=2e9;
int mx[N][N],mn[N][N],ar[N];
void solve() {
  int n,q,l,r;cin>>n>>q>>l>>r;
  for(int i=1;i<=n;++i)cin>>ar[i];

  for(int i=n;i>=1;--i){
    for(int j=0;j<=n;++j){
      mx[i][j]=-INF,mn[i][j]=INF;
      if(!j)continue;
      for(int h=l;h<=r;++h){
        if(i+h>n){
          mx[i][j]=max(mx[i][j],ar[i]);
          mn[i][j]=min(mn[i][j],ar[i]);
          continue ;
        }

        if(mx[i+h][j-1]!=-INF) mx[i][j]=max(mx[i][j],mx[i+h][j-1]+ar[i]);
        if(mn[i+h][j-1]!=INF) mn[i][j]=min(mn[i][j],mn[i+h][j-1]+ar[i]);
      }
    }
  }

  while(q--){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int x=mx[a][b],y=mn[c][d];
    if(x==-INF)x=0;if(y==INF)y=0;
    cout << x+y << '\n';
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}

