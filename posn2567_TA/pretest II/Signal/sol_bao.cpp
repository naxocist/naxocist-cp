// C2T18 - Signal
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, t, d; cin >> n >> m >> t >> d;
  vector<int> in(n);
  set<int> root;
  vector<pair<int, int>> tt;

  for(int i=0; i<m; i++) {
    int a, b; cin >> a >> b; in[b]++;
  }

  for(int i=0; i<t; i++) {
    int a, b; cin >> a >> b; tt.emplace_back(a, b);
  }

  for(int i=0; i<n; i++) {
    if(in[i] == 0) root.insert(i);
  }

  if(root.size()-1 == d) {
    cout << 0;
    return 0;
  }

  int c = 1;
  for(auto [a, b] : tt) {
    auto it_b = root.find(b);
    if(it_b != root.end()) root.erase(it_b);

    if(root.size()-1 == d) {
      cout << c;
      return 0;
    }

    c++;
  }

  cout << -1;
  return 0;
}
