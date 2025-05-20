#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 1;
pair<int, char> ar[N][10];
map<char, int> op;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, q; cin >> n >> m >> q;

  for(int i=0; i<m; ++i) {
    char c; cin >> c;
    op[c] = i;
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
    	char in, out; int cur, nxt; cin >> cur >> in >> nxt >> out;
    	ar[i][op[in]] = {nxt, out};
    }
  }

  string s; cin >> s;

  while(q--) {
    int l, r; cin >> l >> r; 

  }

  return 0;
}
