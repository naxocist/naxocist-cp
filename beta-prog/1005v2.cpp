#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;

  int res = 0, mx = 0, l, r, a, b;
  for(int i=0; i<n; ++i) {
    if(mx < 0) l = i, r = i, mx = v[i];
    else mx += v[i], r ++;
    if(mx > res) res = mx, a = l, b = r;
  }

  if(res == 0) cout << "Empty sequence", exit(0);

  for (int i=a; i<=b; ++i) cout << v[i] << ' '; cout << '\n';
  cout << res;
  return 0;
}

