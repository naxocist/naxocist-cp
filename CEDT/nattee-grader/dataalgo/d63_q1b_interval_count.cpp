#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<int> v(n); for(auto &x : v) cin >> x;

  #define all(x) x.begin(), x.end()
  sort(all(v));

  while(m --) {
    int p; cin >> p;

    auto r = upper_bound(all(v), p + k);
    auto l = lower_bound(all(v), p - k);

    cout << r - l << ' ';
  }
  return 0;
}
