#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 3e2 + 3;
int a[N], b[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; 
  a[0] = b[0] = 1;
  for(int i=1; i<=n; ++i) cin >> a[i];
  for(int i=1; i<=n; ++i) cin >> b[i];

  int res = 0;
  for(int i=1; i<=n; ++i) {
  	int l = a[i-1], r = a[i], x = b[i-1], y = b[i];
  	if(l > r) swap(l, r);
  	if(x > y) swap(x, y);

  	if(l == x and r == y) { res ++; continue ; }
  	int c = (x < l and l < y) + (x < r and r < y);
  	if(c != 1) continue ;

  	if(x < l and l < y and r != x and r != y) res ++;
  	if(x < r and r < y and l != x and l != y) res ++;
  }

  cout << res;
  return 0;
}
