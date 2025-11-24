#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e3 + 3;
ll edge[N], c[N], qs[N];

ll tt[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  for (int i = 2; i <= n; ++i) {
    cin >> edge[i];
    qs[i] = edge[i];
    qs[i] += qs[i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  for (int i = n; i >= 1; --i) {
    tt[i - 1] = c[i] * edge[i];
    if (i > 0)
      tt[i - 1] += tt[i];
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    u++, v++;

    if (u < v) {
      ll res = LLONG_MAX;
      for (int i = 1; i <= u; ++i) {
        res = min(res, (tt[i] - tt[u]) + (qs[v] - qs[i]) * c[i]);
      }
      cout << res << '\n';
      continue;
    }
    // u > v

    ll res = tt[v] - tt[u];
    cout << res << '\n';
  }
  return 0;
}

/*
5 3
1 2 3 4
1 2 3 4 4
2 3
4 1
1 3
*/
