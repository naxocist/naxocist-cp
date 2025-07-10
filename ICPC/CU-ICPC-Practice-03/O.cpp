#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;

  map<int, int> mp;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    mp[x] ++;
  }

  priority_queue<int> pq;
  for(auto [a,b]:mp)pq.emplace(b);

  int res = n;
  while(pq.size() >= 2) {
    int a= pq.top(); pq.pop();
    int b= pq.top(); pq.pop();
    a--,b--;
    res-=2;
    if(a)pq.emplace(a);
    if(b)pq.emplace(b);
  }

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
