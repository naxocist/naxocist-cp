#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) 
    for(int j=0; j<i; ++j) 
      cout << (j and j!=i-1 and i!=n) << " \n"[j==i-1];
  return 0;
}
