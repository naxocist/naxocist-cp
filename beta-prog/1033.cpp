#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
#define FOR(x,n) for(int x = 0; x < n; ++x)

using pi = pair<int, int>;
const int K = 1e3 + 1, N = 1e2 + 1;
vector<int> v[K];
int ar[N][N];
pi pos[4];

int t[] = {1, 0, -1, 0, 1};
char dir[] = {'S', 'W', 'N', 'E'};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;

  pos[0] = {0, n-1}, pos[1] = {n-1, n-1}, pos[2] = {n-1, 0}, pos[3] = {0, 0};
  memset(ar, -1, sizeof ar);

  unordered_map<char, int> um;
  FOR(i, 4) {
    auto [x, y] = pos[i];
    um[dir[i]] = ar[x][y] = i;
  }

  char c;
  FOR(i, 4) FOR(j, k) cin >> c, v[i].pb(um[c]);

  auto ok = [&](int a, int b) {
    return a >= 0 and b >= 0 and a < n and b < n;
  };

  FOR(j, k) {
    FOR(i, 4) {
      auto [x, y] = pos[i];
      int g = v[i][j];
      int nx = x + t[g], ny = y + t[g + 1];
      if(!ok(nx, ny)) continue ;

      FOR(h, 4) {
        if(h == i) continue ;
        if(pos[h] == pi(nx, ny)) goto gg;
      }
      ar[nx][ny] = i;
      pos[i] = {nx, ny};

      gg:;
    }
  }


  int mx = 0, cnt[4] = {};
  FOR(i, n) {
    FOR(j, n) {
      if(ar[i][j] == -1) cout << "No", exit(0);
      mx = max(mx, ++cnt[ar[i][j]]);
    }
  }

  vector<int> r;
  FOR(i, 4) if(cnt[i] == mx) r.pb(i);
  cout << r.size() << ' ' << mx << ln;
  for(auto x : r) cout << x + 1 << ln;
  return 0;
}
