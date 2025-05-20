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
char a[5][N];
void solve() {
	string s;cin>>s;int n=s.size();
	for(int h=0;h<n;++h){
		int mc=2+h*4;
		for(int i=-2;i<=2;++i){
			for(int j=-2;j<=2;++j){
				char &t=a[2+i][mc+j];
				if(abs(i)+abs(j)==2)t=(h+1)%3 and t!='*'?'#':'*';
				else t='.';
			}
		}
		a[2][mc]=s[h];
	}
	for(int i=0;i<5;++i){
		for(int j=0;j<4*n+1;++j)cout<<a[i][j];
		cout<<'\n';
	}
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
