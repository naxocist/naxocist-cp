#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int y; cin >> y;
  if(y < 0) cout << "year cannot be negative", exit(0);

  if(y % 400 == 0) cout << "leap year";
  else if(y % 100 == 0) cout << "not leap year";
  else if(y % 4 == 0) cout << "leap year";
  else cout << "not leap year";
  return 0;
}