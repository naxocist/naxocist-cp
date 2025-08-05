#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n, s; cin >> n >> s;
  vector<int> cnt(3);
  int k = 0;
  while(n--) {
    int x; cin >> x; cnt[x] ++;
    k += x;
  }

  if(s == k) {
    cout << -1 << ln;
    return ;
  }

  int d = s - k;
  if(d > 1) {
    cout << -1 << ln;
    return ;
  }

  for(int i=0; i<cnt[0]; ++i) cout << 0 << ' ';
  for(int i=0; i<cnt[2]; ++i) cout << 2 << ' ';
  for(int i=0; i<cnt[1]; ++i) cout << 1 << ' ';
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
