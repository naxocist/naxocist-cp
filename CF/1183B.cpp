#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;

  vector<int> cnt(n);
  for(int i=0; i<n; ++i) {
    int x; cin >> x; x --; cnt[x] ++;
    int f; cin >> f;
    
  }

  sort(cnt.rbegin(), cnt.rend());

  int res = cnt[0];
  for(int i=1; i<cnt.size(); ++i) {
    if(cnt[i] >= cnt[i-1]) cnt[i] = cnt[i-1] - 1;
    if(cnt[i] <= 0) break ;
    res += cnt[i];
  }


  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
