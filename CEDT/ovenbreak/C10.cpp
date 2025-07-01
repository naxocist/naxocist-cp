#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int d[1001];
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=2; i<=1e3; ++i) {
    if(d[i]) continue ;
    d[i] = i;
    for(int j=i*i; j<=1e3; j+=i) d[j] = i;
  }

  int res = 0;
  while(n != 1) {
    res += d[n];
    n /= d[n];
  }
  cout << res;
  return 0;
}