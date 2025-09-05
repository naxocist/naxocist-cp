#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  vector<int> v;
  int n; cin >> n;
  int k = 0;
  while(n--) {
    int x; cin >> x;
    if(k&1) v.insert(begin(v), x);
    else v.pb(x);
    k^=1;
  }

  while(cin >> n) {
    if(n == -1) break ;
    if(k&1) v.insert(begin(v), n);
    else v.pb(n);
    k^=1;
  }

  cout << "[";
  for(int i=0; i<(int)v.size(); ++i) {
    if(i) cout << ", ";
    cout << v[i];
  }
  cout << "]";
  return 0;
}

