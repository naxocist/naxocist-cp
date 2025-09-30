#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  set<int> s;
  vector<int> v;
  int n; cin >> n;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    s.insert(x);
    v.pb(x);
  }

  cout << s.size() << ln;
  for(auto x : v) {
    if(s.find(2*x) != s.end()) cout << 1;
    else cout << 0;
    cout << ' ';
  }

  return 0;
}

