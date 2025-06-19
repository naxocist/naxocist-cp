#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  // 8/8 6/8 4/8 2/8 1/8
  int ar[5] = {}, t[] = {8, 6, 4, 2, 1};
  while(n--) {
    for(int i=0, x; i<5; ++i) cin >> x, ar[i] += x;
  }

  int res = 0;
  for(int i=0; i<5; ++i) res += ar[i]*t[i];
  cout << (res + 7)/8;
  return 0;
}

