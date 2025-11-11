#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8 + 7;
const int N = 1e7 + 3;
int ar[N][3];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  vector<pair<int, int>> state = {
    {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 2},
    {2, 0}, {2, 1},
  };
  ar[0][0] = 1;
  for(int i=1; i<=n; ++i) {
    for(auto &[a, b] : state) {
      ar[i][a] += ar[i-1][b];
      ar[i][a] %= mod;
    }
  }

  int res = 0;
  for(int i=0; i<4; ++i) res += ar[n][i], res %= mod;
  cout << res;
  return 0;
}
