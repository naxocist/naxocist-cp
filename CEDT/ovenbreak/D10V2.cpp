#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;

  int st = -1, ed = -1;
  for(int i=0; i<n; ++i) {
    char s = a[i], z = b[i];
    if(s == 'S' or z == 'S' or s == 'T' or z == 'T') {
      if(st == -1) st = i;
      else ed = i;
    }
  }

  if(ed == -1) ed = st;
  bool no = 0;
  for(int i=st; i<ed; ++i) {
    if((a[i] == '#' and b[i] == '#') or (a[i] == '#' and b[i+1] == '#') or (a[i+1] == '#' and b[i] == '#')) no = 1;
  }

  cout << (no ? "No" : "Yes") << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
