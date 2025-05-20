#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b; cin >> a >> b;

  ll res = 0;
  vector<bool> noprime(b*3);
  for(int p=2; p<b*3; ++p) {
    if(noprime[p]) continue ;

    if(a*3 < p and p < b*3) {
      for(int A=a; A<=b; ++A) {
        int BC = p - A;
        int x = max(A, BC - b);
        int y = min(b, BC - A);
        if(y < x) continue ;
        res += (y-x+2)/2;
      }
    }

    for(int j=p*p; j<b*3; j+=p) noprime[j] = 1;
  }

  cout << res;
  return 0;
}
