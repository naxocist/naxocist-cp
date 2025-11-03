#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v;
  while(n != 1) {
    v.pb(n);
    if(n&1) n = 3*n + 1;
    else n /= 2;
  }
  v.pb(1);

  int t = v.size();
  bool first = 1;
  for(int i=max(0, t-15); i<t; ++i) {
    if(!first) cout << "->";
    cout << v[i];
    first = 0;
  }

  return 0;
}

