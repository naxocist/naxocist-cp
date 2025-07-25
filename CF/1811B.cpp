#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  while(q--) {
    int x, y, a, b, n; cin >> n >> x >> y >> a >> b;

    int lxy = min({x,y,n-x+1,n-y+1});
    int lab = min({a,b,n-a+1,n-b+1});
    cout << abs(lxy-lab) << '\n';
  }
  return 0;
}
