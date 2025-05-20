#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c; cin >> a >> b >> c;
  int x = a%2 + b%2 + c%2;

  printf("even %d\nodd %d", 3-x, x);
  return 0;
}
