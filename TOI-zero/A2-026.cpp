#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;
  int mx = INT_MIN, c = 0; string t;
  while(q--) {
  	string s; int x; cin >> s >> x;
  	c += x > 15;
  	if(x > mx) {
  		t = s;
  		mx = x;
  	}
  }
  cout << c << ln << t << ' ' << mx;
  return 0;
}
