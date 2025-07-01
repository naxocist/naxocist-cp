#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  
  int x; cin >> x;
  if(x > 180) cout << "Burnt";
  else if(x >= 160) cout << "Perfect";
  else cout << "Undercooked";
  return 0;
}