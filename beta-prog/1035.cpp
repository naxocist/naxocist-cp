#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  auto prime = [&](ll x) {
    for(ll i=2; i*i<=x; ++i) {
      if(x % i == 0) return 0;
    }
    return 1;
  };

  auto palin = [&](ll x) {
    string s = to_string(x);
    bool t = 1;
    for(int i=0,j=s.size()-1; i<j; i++, j--) if(s[i] != s[j]) t = 0;
    return t;
  };

  for(ll i=n; ; ++i) {
    if(prime(i) and palin(i)) cout << i, exit(0);
  }

  return 0;
}
