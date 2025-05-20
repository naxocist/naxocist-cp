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
  string a,b;char c;cin>>a>>c>>b;
  int na=a.size(),nb=b.size();
  if(c=='*'){
  	cout<<1;int k=na+nb-2;while(k--)cout<<0;
  	return ;
  }
  reverse(all(a));reverse(all(b));
  string r;
  for(int i=0;i<max(na,nb);++i){
  	if(i<min(na,nb))r+=a[i]+b[i]-'0';
  	else r+=na>nb?a[i]:b[i];
  }
  reverse(all(r));
  cout<<r;

  // if(na==nb){
  // 	cout<<2;int k=na-1;while(k--)cout<<0; 
  // 	return ;
  // }
  // if(na<nb)swap(a,b),swap(na,nb);
  // cout<<1;int k=na-nb-1;while(k--)cout<<0;cout<<1;k=nb-1;while(k--)cout<<0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
