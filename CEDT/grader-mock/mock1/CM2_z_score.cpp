#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  double z; cin >> z;
  double x;

  double sd = 0;
  double xb = 0;
  double sqs = 0;
  int n = 0;

  while(cin >> x) {
    if(x == -1) break ;
    xb += x;
    sqs += x*x;
    n++;
  }
  xb /= n;
  sqs /= n;

  sd += sqs - xb*xb;
  sd = sqrt(sd);

  double res = z * sd  + xb;

  cout << fixed << setprecision(5) << res;
  return 0;
}
