#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;

  map<string, int> cnt;
  while(n --) {
    string s; cin >> s; cnt[s] ++;
  }

  priority_queue<pair<int, string>> pq;
  for(auto &[a, b] : cnt) {
    pq.emplace(b, a);
  }

  while(pq.size()) {
    auto [a, b] = pq.top(); pq.pop();
    if(--k == 0 or pq.empty()) {
      cout << a;
      break ;
    }
  }


  return 0;
}
