#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;

  for(int i=n-1; i>=0; --i) {
    if(a[i] == b[i]) continue;

    if(i == n-1) {
      if(a[i] != b[i]) {
        cout << "NO" << ln;
        return ;
      }
    }else {
      int w = a[i]^b[i];
      if(w != b[i+1] and w != a[i+1]) {
        cout << "NO" << ln;
        return ;
      }
    }
  }


  cout << "YES\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t; while(t--) solve();
  return 0;
}
