#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

char ar[2][503];

void solve() {
  int n; cin >> n;

  int r, c;
  for(int i=0; i<2; ++i) {
    string s; cin >> s;
    for(int j=0; j<n; ++j) {
      char t = s[j];
      ar[i][j] = t;
      if(t == 'S') r=i,c=j;
    }
  }

  using pi = pair<int, int>;
  queue<pi> q;
  q.emplace(r,c);
  while(q.size()) {
    pi t = q.front(); q.pop();
    int x = t.first, y = t.second;
    if(x < 0 or y < 0 or x >= 2 or y >= n or ar[x][y] == '#' or ar[x][y] == '?') continue ;
    if(ar[x][y] == 'T') {
      cout << "Yes\n";
      return ;
    }
    ar[x][y] = '?';
    q.emplace(x^1,y);
    q.emplace(x,y+1);
    q.emplace(x,y-1);
  }
  cout << "No\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
