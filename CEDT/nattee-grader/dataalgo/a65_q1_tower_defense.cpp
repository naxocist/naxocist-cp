#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k, w; cin >> n >> m >> k >> w;

  int res = 0;
  vector<int> pos(m);
  priority_queue<pair<int, int>> mon;
  for(auto &x : pos) cin >> x;
  for(int i=0; i<m; ++i) {
    int x; cin >> x; res += x;
    mon.emplace(x, pos[i]);
  }

  vector<pair<int, int>> v;
  vector<bool> no(k);
  for(int i=0; i<k; ++i) {
    int x; cin >> x;
    int l = x - w, r = x + w;
    v.emplace_back(l, r);
  }

  while(mon.size()) {
    auto [h, p] = mon.top(); mon.pop();
    for(int i=0; i<k and h>0; ++i) {
      auto [l, r] = v[i];
      if(l <= p and p <= r and !no[i]) {
        res --; h --;
        no[i] = 1;
      } 
    }
  }

  cout << res;

  return 0;
}
