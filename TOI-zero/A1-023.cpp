#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; char c; cin >> t >> c; c = tolower(c);

  if(c == 'c') {
    if(t <= 0) cout << "solid";
    else if(t < 100) cout << "liquid";
    else cout << "gas";
  }else {
    if(t <= 32) cout << "solid";
    else if(t < 212) cout << "liquid";
    else cout << "gas";
  }
  return 0;
}
