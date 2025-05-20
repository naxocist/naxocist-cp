#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  char c; int x; cin >> c >> x;

  cout << "safe ";
  if(c == 'H' and x == 4567) cout << "unlocked";
  else if(c != 'H' and x == 4567) cout << "locked - change char";
  else if(c == 'H') cout << "locked - change digit";
  else cout << "locked";
  return 0;
}
