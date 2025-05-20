#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  for(int i=0; i<3 and n >= 1; ++i){
    int k = n; while(k--) cout << "*"; cout << ln;
    n -= 2;
  }
  return 0;
}
