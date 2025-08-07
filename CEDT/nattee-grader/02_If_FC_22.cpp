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
  int n = 31;


  // 4 6 9 11
  if(m == 4 or m == 6 or m == 9 or m == 11) n = 30;
  else if(m == 2) {
    n = 28;
    if(y % 400 == 0) n ++;
    else if(y % 4 == 0 and y % 100) n ++;
  }

  d += 15;
  if(d > n) d -= n, m ++;
  if(m > 12) m -= 12, y ++;

  y += 543;

  printf("%d/%d/%d",d,m,y);
  return 0;
}
