#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  map<string, set<int>> mp;
  while(n --) {
    string s; int x; cin >> s >> x;
    mp[s].insert(x);
  }

  int res = 0;
  for(auto &[a, b] : mp) {
    if((int)b.size() == k) res ++;
  }
  cout << res;
  return 0;
}

