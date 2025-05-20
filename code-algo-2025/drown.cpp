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

const int N = 1e3 + 1;
vector<pll> d[N];

void solve() {
  ll n,m,h,t,p;cin>>n>>m>>h>>t>>p;

  while(m--){
    ll x,tt,hh;cin>>x>>tt>>hh;
    d[x].pb(tt,hh);
  }
  vector<int> r;
  for(int i=1;i<=n;++i){
    if(h==0){ r.pb(i); continue; }
    auto v=d[i];
    sort(all(v));
    v.pb(LLONG_MAX,v.back().second);
    bool ok=1,ok2=0;
    for(int j=1;j<v.size();++j){
      auto [t1,h1]=v[j-1]; 
      auto [t2,h2]=v[j];
      if(h1>=h){ r.pb(i); break ; }
      if((t2-t)*p>h1)ok=0;
      if(!ok) break ;
      if(h2>=h){ r.pb(i); break ; }
    }
  }

  cout<<r.size()<<ln;for(auto x:r)cout<<x<<' ';
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}

