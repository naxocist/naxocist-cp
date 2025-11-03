#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int d1, m1, y1; cin >> d1 >> m1 >> y1;
  int d2, m2, y2; cin >> d2 >> m2 >> y2;
  y1 -= 543; y2 -= 543;


  int res = (y2-y1-1) * 365;


  bool leap1 = 0;
  if(y1 % 400 == 0) leap1 = 1;
  else if(y1 % 4 == 0 and y1 % 100) leap1 = 1;
  else leap1 = 0;

  bool leap2 = 0;
  if(y2 % 400 == 0) leap2 = 1;
  else if(y2 % 4 == 0 and y2 % 100) leap2 = 1;
  else leap2 = 0;

  m1--, m2--;

  // 4 6 9 11
  for(int i=0; i<m2; ++i) {
    if(i == 3 or i == 5 or i == 8 or i == 10) res += 30;
    else if(i != 1) res += 31;
    else {
      res += 28 + leap2;
    }
  }
  res += d2-1;

  int s = d1;
  for(int i=0; i<m1; ++i) {
    if(i == 3 or i == 5 or i == 8 or i == 10) s += 30;
    else if(i != 1) s += 31;
    else {
      s += 28 + leap1;
    }
  }

  res += (leap1 ? 366 : 365) - s + 1;

  double f = 2*M_PI*res;
  double a = sin(f/23);
  double b = sin(f/28);
  double c = sin(f/33);

  a = round(a*100.0)/100.0;
  b = round(b*100.0)/100.0;
  c = round(c*100.0)/100.0;
  cout << res << ' ' << a << ' ' << b << ' ' << c;
  return 0;
}
