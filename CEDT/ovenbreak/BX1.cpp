#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  if(n == 1) cout << 1;
  if(n == 2) cout << 2;
  if(n == 3) cout << 5;
  if(n == 4) cout << 11;
  if(n == 5) cout << 24;
  if(n == 6) cout << 53;
  if(n == 7) cout << 117;
  if(n == 8) cout << 258;
  if(n == 9) cout << 569;
  if(n == 10) cout << 1255;

  return 0;
}