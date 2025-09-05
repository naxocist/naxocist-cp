#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;

const int LG = 20;
const int N = 1e5 + 3;

void func(int b[][5]) {
  cout << sizeof(b) << ln;
}


int32_t main() {
  int a[7] = {};
  a[1] = 9999;
  int b[3][5] = {1, 2, 3, 4 ,5, 6,7,8,9,10,11,12,13,14,15};
  for(int i=0; i<3; ++i) {
    for(int j=0; j<2; ++j) {
      cout << b[i][j] << ' ';
    }
    cout << ln;
  }
  cout << sizeof(a) << " " << sizeof(*a) << ln;
  func(b);
}

