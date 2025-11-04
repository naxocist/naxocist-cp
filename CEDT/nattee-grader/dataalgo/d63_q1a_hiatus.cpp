#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  set<pair<int, int>> s;
  while(n --) {
    int a, b; cin >> a >> b; s.emplace(a, b);
  }

  while(q --) {
    int a, b; cin >> a >> b;
    auto t = s.upper_bound({a, b});
    if(t == s.begin()) cout << "-1 -1";
    else if(*prev(t) == make_pair(a, b)) cout << "0 0";
    else t--, cout << (*t).first << ' ' << (*t).second;
    
    cout << " ";
  }
  return 0;
}
