#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n + 1);
  v[0] = 0, v[1] = 1;
  for(int i=2; i<=n; ++i) v[i] = v[i-1] + v[i-2];
  cout << v[n];
  return 0;
}
