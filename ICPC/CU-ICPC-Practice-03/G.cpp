#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> cnt(51);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x, cnt[x]++;

  sort(v.begin(), v.end());
  int res = 0;
  for(int i=2*n; i>=2; --i) {
    vector<int> t = cnt;
    int r = 0;
    for(auto x : v) {
      if(i-x<0 or i-x>50 or t[x]<0) continue ;
      t[x]--;
      r += t[i-x]-- > 0;
    }
    res = max(res, r);
  }
  
  cout << res << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
