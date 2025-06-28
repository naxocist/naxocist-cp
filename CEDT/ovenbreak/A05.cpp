#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  double x1, x2, y1, y2, scale, speed;
  cin >> scale >> speed >> y1 >> x1 >> y2 >> x2;

  x1 += x2; y1 += y2;
  double dis_km = scale*(sqrt(x1*x1 + y1*y1));

  double time_h = dis_km / (speed*(18.0/5));
  ll h = time_h;
  cout << h << " hr " << ceil((time_h-h)*60) << " min";
  return 0;
}
