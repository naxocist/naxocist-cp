#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string t; cin >> t;
  int k; cin >> k;

  t += '.';
  int n = t.size();
  int cnt = 0;
  char p = '.';
  int idx = -1;

  string res;
  for(int i=0; i<n; ++i) {
    char c = t[i];
    if(c == p) cnt ++;
    else {
      if(idx != -1 and cnt < k) {
        res += t.substr(idx, cnt);
      }
      p = c;
      cnt = 1;
      idx = i;
    }

  }

  cout << res;
  return 0;
}

