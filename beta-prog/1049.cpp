#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define allrev(x) rbegin(x), rend(x)
#define pb emplace_back

const int N = 1e5 + 3, M = 1e4 + 3;
int mx[N], id[N], t[N], cnt[M];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i=0; i<n; ++i) t[i] = INT_MAX;

  int lim = 0;
  for(int i=0; i<n; ++i) {
    int a, l, s; cin >> a >> l >> s;
    int row = cnt[l]++;
    if(s > mx[row] or (s == mx[row] and l < t[row])) {
      mx[row] = s;
      t[row] = l;
      id[row] = a;
    }

    lim = max(lim, cnt[l]);
  }

  for(int i=0; i<lim; ++i) cout << id[i] << ln;
  return 0;
}
