#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double x; cin >> x;

  if(x >= 80) {
    cout << "A";
  }else if(x >= 70) {
    cout << "B";
  }else if(x >= 60) {
    cout << "C";
  }else if(x >= 50) {
    cout << "D";
  }else {
    cout << "F";
  }
  return 0;
}
