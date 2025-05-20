#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 3;
int lf[N], rt[N], wl[N], wr[N], w[N];


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int res = 0;
  for(int u=1; u<=n; ++u){
  	int a, l, b, r; cin >> a >> l >> b >> r; 
  	if(a and b) {
  		res += abs(l - r);
  		w[u] = 2*max(l, r);
  		continue ;
  	} 

  	if(a) wl[u] = l;
  	else lf[u] = l;
  	if(b) wr[u] = r;
  	else rt[u] = r;
  }

  for(int u=n; u>=1; --u) {
  	if(!lf[u] and !rt[u]) continue ;

  	int ll = wl[u], rr = wr[u];
  	if(lf[u]) ll = w[lf[u]];
  	if(rt[u]) rr = w[rt[u]];

  	res += abs(ll - rr);
  	w[u] = 2*max(ll, rr);
  }

  cout << res;
  return 0;
}
