#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double w; int n; cin >> w >> n;
  vector<double> V(n), W(n);
  for(auto &x : V) cin >> x;
  for(auto &x : W) cin >> x;

  priority_queue<pair<double, int>> pq;
  for(int i=0; i<n; ++i) {
    pq.emplace(V[i]/W[i], i);
  }

  double res = 0;
  while(pq.size()) {
    auto [t, i] = pq.top(); pq.pop();

    if(w >= W[i]) {
      res += V[i];
      w -= W[i];
      continue;
    }

    res += t*w;
    break ;
  }

  cout << fixed << setprecision(4) << res;
  return 0;
}
