#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n; vector<int> a(n); for(auto &x : a) cin >> x;
  int m; cin >> m; vector<int> b(m); for(auto &x : b) cin >> x;
  sort(all(a));
  sort(all(b));

  // for(auto x : a) cout << x << ' ' ; cout << endl;
  // for(auto x : b) cout << x << ' ' ; cout << endl;

  int k = 0, res = 0;
  for(int i=0; i<n; ++i) {
    for(int j=k; j<m; ++j) {
      if(abs(a[i] - b[j]) <= 1) {
        k = j + 1;
        res ++;
        break ;
      }
    }
  }

  cout << res;
  return 0;
}
