#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    int n, k; cin >> n >> k;
    k --;
    int f = n/2;
    cout << (k + (n%2)*k/f) % n + 1 << ln;
  }
  return 0;
}
