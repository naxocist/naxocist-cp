#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int res = 1;
  int x;

  unordered_set<int> s;
  while(cin >> x) {
    if(s.find(x) != s.end()) break ;
    res ++;
    s.insert(x);
  }

  cout << res;

  return 0;
}

