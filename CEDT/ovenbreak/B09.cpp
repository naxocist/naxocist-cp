#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double s, h, w; cin >> s >> h >> w;
  if(h < 100 or w > 200) cout << "It too weak.", exit(0);

  if(s > 100) cout << "It can jump over.";
  else cout << "It can't jump over.";
  return 0;
}