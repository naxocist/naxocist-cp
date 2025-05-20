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

void solve() {
  string s;cin>>s;
  int a=1;
  for(auto c:s){
  	if(c=='A')a=a==1?2:a==2?1:a;
  	if(c=='B')a=a==2?3:a==3?2:a;
  	if(c=='C')a=a==1?3:a==3?1:a;
  }
  cout<<a;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
