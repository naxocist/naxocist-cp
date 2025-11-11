#include <bits/stdc++.h>
using namespace std;

int ar[4][4];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  vector<int> v(n); 
  vector<int> cnt(4);
  for(int i=0; i<n; ++i) {
    int x; cin >> x; v[i] = x;
    cnt[x] ++;
  }

  for(int i=0; i<n; ++i) {
    int z = 1;
    if(i >= cnt[1]) {
      if(i >= cnt[1] + cnt[2]) z = 3;
      else z = 2;
    }
    ar[z][v[i]] ++;
  }

  int res = 0;
  vector<pair<int, int>> p = {{1, 2}, {1, 3}, {2, 3}};
  for(auto [a, b] : p) {
    int d = min(ar[a][b], ar[b][a]);
    res += d;
    ar[a][b] -= d;
    ar[b][a] -= d;
  }

  int c = 0;
  for(int i=1; i<=3; ++i) {
    for(int j=1; j<=3; ++j) {
      if(i == j) continue ;
      c += ar[i][j];
    }
  }

  cout << c << '\n';
  res += 2 * (c/3);
  cout << res;
  return 0;
}
