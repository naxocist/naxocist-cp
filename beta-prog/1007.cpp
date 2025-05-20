#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x;
  while(cin >> x) {
    if(x == -1) break ;
    int a = 1, b = 1, c = 0, tc;
    while(x--) tc = c, c = b, b = a + b + tc;

    cout << b << ' ' << a + b + c << '\n';
  }
  return 0;
}
