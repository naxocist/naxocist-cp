#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

using ll = long long;
const int N = 5003;
int dp[N][N];
char ar[N][N];
set<pi> in;

int f(pi &a, pi &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<pi> v[5];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      ar[i][j] = c;
      if ('1' <= c && c <= '5') {
        v[c - '0' - 1].emplace_back(i, j);
      }
      dp[i][j] = INT_MAX;
    }
  }

  for (int i = 0; i < 5; ++i) {
    if (v[i].empty())
      continue;
    pi ori = {0, 0};
    if (f(v[i][0], ori) > f(v[i][1], ori))
      swap(v[i][0], v[i][1]);
    auto &[x, y] = v[i][0];
    in.emplace(x, y);
  }
  int tr[] = {0, 0, 1};
  int tc[] = {-1, 1, 0};

  using T = tuple<int, int, int>;
  queue<T> pq;
  pq.emplace(0, 1, 1);
  dp[1][1] = 0;

  while (pq.size()) {
    auto [d, a, b] = pq.front();
    pq.pop();
    if (in.find(pi(a, b)) != in.end()) {
      int x = ar[a][b] - '0' - 1;
      auto [q, w] = v[x][1];
      if (dp[a][b] < dp[q][w] and ar[q][w] != 'X') {
        dp[q][w] = dp[a][b];
        pq.emplace(d, q, w);
      }
    }

    for (int i = 0; i < 3; ++i) {
      int na = a + tr[i], nb = b + tc[i];
      if (na < 1 or nb < 1 or na > n or nb > m or ar[na][nb] == 'X')
        continue;
      if (dp[a][b] + 1 < dp[na][nb]) {
        dp[na][nb] = dp[a][b] + 1;
        pq.emplace(-dp[na][nb], na, nb);
      }
    }
  }

  cout << dp[n][m] << '\n';
}
