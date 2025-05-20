#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "-------\n";
#define all(x) begin(x), end(x)
#define cntBit(x) __builtin_popcount(x)
#define pb emplace_back
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  int s = 0; vector<int> v(n);
  for(auto &x : v) cin >> x, s += x;
  s /= n;

  int res = 0;
  for(auto x : v) res += max(0, x-s);
  cout << res;
  return 0;
}
