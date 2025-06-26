#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 4e6 + 3;
int tr[N][26], z;
bool chk[N][26];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  memset(tr, -1, sizeof tr);
  string s, b; cin >> s >> b;
  int k; cin >> k;
  int n = s.size(), res = 0;
  for(int i=0; i<n; ++i) {
    int cb = 0, u = 0;
    for(int j=i; j<n; ++j) {
      int c = s[j] - 'a';
      cb += b[c] == '0';
      if(cb > k) break ;
      if(tr[u][c] == -1) u = tr[u][c] = ++z, res ++;
      else u = tr[u][c];
    }
  }

  cout << res;
  return 0;
}

