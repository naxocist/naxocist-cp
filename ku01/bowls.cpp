#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int ar[301];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int mx = 0;
  while(n--) {
  	int x; cin >> x;
  	mx = max(mx, ++ar[x]);
  }
  cout << mx;
  return 0;
}
