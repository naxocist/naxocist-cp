#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  set<pair<int, int>> s;
  vector<int> st(n);
  for(auto &x : st) cin >> x;

  priority_queue<pair<int, int>> pq;
  for(int i=0; i<n; ++i) {
    int end; cin >> end;
    pq.emplace(-end, st[i]);
  }

  int prv = -1, res = 0;
  while(pq.size()) {
    auto [e, s] = pq.top(); pq.pop();
    if(s < prv) continue ;
    res ++;
    prv = -e;
  }
  cout << res;
  return 0;
}

