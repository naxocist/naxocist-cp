#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, z; cin >> n >> q >> z;

  set<int> s;
  s.insert(1);
  while(q--) {
    int x, l; cin >> x >> l;
    if(s.find(x) != s.end()) s.erase(x);
    else s.insert(x);

    x += l;
    if(s.find(x) != s.end()) s.erase(x);
    else s.insert(x);
  }
  s.insert(1);
  s.insert(n+1);

  while(z--) {
    int x; cin >> x;
    auto t = s.upper_bound(x);
    cout << *t - *prev(t) << '\n';
  }
  return 0;
}
