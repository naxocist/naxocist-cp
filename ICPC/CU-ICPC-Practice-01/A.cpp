#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  int mx = -INT_MAX, mn = INT_MAX, a, b;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    if(x > mx) mx = x, a = i;
    if(x <= mn) mn = x, b = i;
  }

  cout << a + n - b - (a > b) - 1;
  return 0;
}
