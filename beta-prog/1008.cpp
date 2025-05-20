#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q; vector<int> v(256);

  while(q--) {
    int l, h, r; cin >> l >> h >> r;
    for(int i=l; i<r; ++i) v[i] = max(v[i], h);
  }

  for(int i=1; i<256; i++) if(v[i] != v[i-1]) cout << i << ' ' << v[i] << ' ';
  return 0;
}
