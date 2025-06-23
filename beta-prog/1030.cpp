#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e5 + 3;
pair<double, int> ar[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int k; cin >> k;

  for(int i=0; i<k; ++i) {
    double p, q; cin >> p >> q;
    ar[i] = {p/q, q};
  }

  sort(ar, ar+k);

  int m; cin >> m;
  int i = 0;
  while(m--) {
    int x; cin >> x;
    double pay = 0;
    while(ar[i].second <= x)
      x -= ar[i].second, pay += ar[i].first*ar[i].second, i++;

    pay += x*ar[i].first;
    ar[i].second -= x;

    cout << fixed << setprecision(3) << pay << ln;
  }
  return 0;
}
