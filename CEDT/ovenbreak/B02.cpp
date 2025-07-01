#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double tar, r; char t;
  cin >> tar >> t >> r;

  if(t == 't') r /= 1e6;
  else if(t == 'k') r /= 1e3;

  if(r > 1.05*tar) cout << "Too Much";
  else if(r < 0.95*tar) cout << "Add More";
  else if(r != tar) cout << "Pretty Good";
  else cout << "Perfect";
  return 0;
}