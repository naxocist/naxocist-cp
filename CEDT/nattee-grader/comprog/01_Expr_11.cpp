#include <bits/stdc++.h>
using namespace std;

int main() {
  double s = 1;
  for(int i=1; i<=10; ++i) s *= i;
  double z = 1;
  for(int i=0; i<8; ++i) z *= 8;
  s /= z;

  double up = M_PI - s + pow(log(9.7), 7/sqrt(71) - sin(2*M_PI/9));

  double bot = pow(1.2, cbrt(2.3));

  cout << up/bot;
  return 0;
}