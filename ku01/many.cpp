#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k; 
  vector<int> v(n); for(auto &x : v) cin >> x, x--;

  vector<int> cnt(1e5);
  ll res = 0;
  for(int l=0, r=0, d=0; ;) {
    for(; d<k and r<n; ) {
      if(cnt[v[r++]]++ == 0) d ++;
    }
    if(d<k and r==n) break ;
    
    res += n-r+1;
    if(--cnt[v[l++]] == 0) d--;
  }

  cout << res;
  return 0;
}
