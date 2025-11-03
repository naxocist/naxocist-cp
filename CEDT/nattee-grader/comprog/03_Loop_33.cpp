#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  
  int x, y, n = 0;
  string a, b;
  while(1) {
    x = -1, y = INT_MIN;
    cin >> x >> y;
    if(y == INT_MIN) break ;
    a += to_string(x);
    a += " ";
    b += to_string(y);
    b += " ";
    n ++;
  }

  int i = 0, j = 0;
  int idx = 0;
  int m = x;

  int mn = INT_MAX, mx = INT_MIN;
  while(i < a.size() and j < b.size()) {
    int x = stoi(a.substr(i, a.find(" ", i) - i));
    int y = stoi(b.substr(j, b.find(" ", j) - j));

    if(m == -998) {
      if(idx) mn = min(mn, y), mx = max(mx, x);
      else mn = min(mn, x), mx = max(mx, y);
    }else {
      if(idx) mn = min(mn, x), mx = max(mx, y);
      else mn = min(mn, y), mx = max(mx, x);
    }
    idx ^= 1;
    i = a.find(" ", i) + 1;
    j = b.find(" ", j) + 1;

  }
  cout << mn << ' ' << mx;
  return 0;
}

