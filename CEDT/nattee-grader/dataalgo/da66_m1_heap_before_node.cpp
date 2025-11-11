#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k; cin >> n >> k;

  vector<int> res;
  queue<int> q;
  q.emplace(0);
  while(q.size()) {
    int u = q.front(); q.pop();
    if(u >= n or u == k) continue ;
    res.emplace_back(u);
    int l = 2*u + 1, r = 2*u + 2;
    q.emplace(l), q.emplace(r);
  }

  sort(res.begin(), res.end());
  cout << (int)res.size() << '\n';
  for(auto &r : res) cout << r << ' ';
  return 0;
}
