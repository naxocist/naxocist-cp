#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double w, h; cin >> w >> h;

  cout << setprecision(15);

  cout << sqrt(w*h)/60 << ln;
  cout << 0.024265*pow(w,0.5378)*pow(h,0.3964) << ln;
  cout << 0.0333*pow(w,0.6157-0.0188*log10(w))*pow(h,0.3) << ln;
  return 0;
}
