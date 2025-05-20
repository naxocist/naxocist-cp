#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int x = 1;
  while(x*x < n) x ++;

  if(x == 1) cout << 0;
  else if(x <= 2) cout << x-1 + (n != 3);
  else cout << 2*x-3 + (n-x+1)%2; 
  return 0;
}
