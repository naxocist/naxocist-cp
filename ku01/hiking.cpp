#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, d; cin >> n >> d;
  int mn = 0, mx = 0;
  while(n--) {
  	int h; cin >> h;
  	if(h % 4 == 0 and h % 3) mn += 10*h/4, mx += 10*h/4;
  	else if(h % 3 == 0 and h % 4) mn += 10*h/3, mx += 10*h/3;
  	else mn += 10*h/4, mx += 10*h/3;
  }


  cout << d-mx << ' ' << d-mn;
  return 0;
}
