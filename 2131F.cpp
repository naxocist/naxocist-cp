#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double


#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;

  int one = 0, zero = 0;

  int n1 = 0, n0 = 0, tie = 0;
  ll base = 0;
  for(int i=0; i<n; ++i) {
    if(a[i] == '1') one ++;
    else zero ++;

    if(one < zero) base += one, n1 ++;
    else if(zero < one) base += zero, n0 ++;
    else base += one, tie ++;
  }

  ll res = 0;

  one = 0, zero = 0;
  for(int i=0; i<n; ++i) {
    if(b[i] == '1') one ++, res += base + one*n1;
    else zero ++, res += base += zero*n0;
  }

  cout << res << ln;
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t; while(t--) solve();
  return 0;
}
