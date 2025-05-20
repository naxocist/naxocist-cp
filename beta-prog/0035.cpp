#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<double, double>
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

#define f first
#define s second
void solve() {
  int n;cin>>n;
  vector<pii> v(n);for(auto &[a,b]:v)cin>>a>>b;
  auto cal=[&](int i, int j, int k)->double{
    auto [x1,y1]=v[i];
    auto [x2,y2]=v[j];
    auto [x3,y3]=v[k];
    return abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)/2;
  };
  double mx=0;
  for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) for(int k=j+1;k<n;++k) mx=max(mx,cal(i,j,k));
  cout<<fixed<<setprecision(3)<<mx;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
