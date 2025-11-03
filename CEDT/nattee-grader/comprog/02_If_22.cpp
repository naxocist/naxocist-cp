#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int d, m, y; cin >> d >> m >> y;
  y -= 543;
  m --;

  bool leap = 0;

  if(y % 400 == 0) leap = 1;
  else if(y % 4 == 0 and y % 100) leap = 1;
  else leap = 0;

  int s = 0;
  // 4 6 9 11
  for(int i=0; i<m; ++i) {
    if(i == 3 or i == 5 or i == 8 or i == 10) s += 30;
    else if(i != 1) s += 31;
    else {
      s += 28 + leap;
    }
  }

  s += d;

  cout << s;

  return 0;
}
