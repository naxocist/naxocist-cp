#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  string t; cin >> t;
  while(--q) {
    string s; cin >> s; int m = s.size();

    if(m != n) break ;

    int dff = 0;
    for(int i=0; i<m; ++i) dff += s[i] != t[i];

    if(dff > 2) break ;

    t = s;
  }

  cout << t;
  return 0;
}
