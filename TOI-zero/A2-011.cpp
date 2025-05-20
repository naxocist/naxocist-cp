#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int k = 10;
  unordered_set<int> us;
  while(k--) {
  	int x; cin >> x;
  	if(us.find(x) == us.end()) cout << x << ' ';
  	us.insert(x);
  }
  return 0;
}
