#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double a; cin >> a;

  double l = 0, r = a;
  double m = l + (r-l)/2;
  while(abs(a-pow(10,m)) > pow(10, -10)) {
    if(pow(10,m) > a) r = m;
    else if(pow(10,m) < a) l = m;
    m = l + (r-l)/2;
  }

  cout << m;
  return 0;
}

