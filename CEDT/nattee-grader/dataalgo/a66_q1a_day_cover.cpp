#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;

  vector<bitset<1000>> v(k);
  for(int i=0; i<k; ++i) {
    int m; cin >> m;
    while(m --) {
      int d; cin >> d; d --;
      v[i].set(d);
    }
  }

  int res = INT_MAX;
  for(int i=0; i<1<<k; ++i) {
    bitset<1000> ok;
    int cnt = 0;
    for(int j=0; j<k; ++j) {
      if(i&(1<<j)) {
        cnt ++;
        ok |= v[j];
      }
    }
    
    if((int)ok.count() == n) {
      res = min(res, cnt);
    }
  }
  cout << res;
  return 0;
}


