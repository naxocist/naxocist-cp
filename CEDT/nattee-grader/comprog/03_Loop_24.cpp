#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;

  char p = '.';
  s += p;
  int cnt = 0;
  for(char c : s) {
    if(c == p) cnt ++;
    else {
      if(p != '.') cout << p << ' ' << cnt << ' ';
      cnt = 1;
      p = c;
    }
  }
  return 0;
}

