#include <bits/stdc++.h>
using namespace std;

#define P 3.28
#define S 1.15112
#define N 4.80852
#define D 69
#define L0 13.0725

int main() {
  double i, v, l, h, zeta, px, py, d;
  cin >> i >> v >> l >> h >> zeta >> px >> py >> d;

  zeta *= (3.14159/180);

  double Mp1 = cos(zeta)*px - sin(zeta)*py;
  double Mp2 = sin(zeta)*px + py;
  double absMp = sqrt(Mp1*Mp1 + Mp2*Mp2);

  double up = tan((absMp/L0)*P) * i * v;
  long long cexp = ceil(exp(N*d));
  double bot = l * (cexp % D) * pow(h, 1.0/3);

  double r = abs(cbrt(up / bot));
  double res = P * log2(r) / log2(S);
  cout << round(res * 1e4)/1e4 << ' ' << " NP";
  return 0;
}
