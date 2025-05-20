#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int l, n; cin >> l >> n;
  int i = 0;
  for(int x=0; x<n; x+=l*(l+1)/2 + i*l*l, i++);
  cout << i;
  return 0;
}
