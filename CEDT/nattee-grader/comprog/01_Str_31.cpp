#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back


long gcd(long a, long b) {
 if (b == 0) return a;
 return gcd(b, a%b);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b, c; cin >> a >> b >> c;

  ll x = stoi(b+c) - stoi(b);

  string t;
  for(int i=0; i<c.size(); ++i) t += '9';
  for(int i=0; i<b.size(); ++i) t += '0';

  ll y = 0;
  for(int i=0; i<t.size(); ++i) {
    y *= 10;
    y += t[i] - '0';
  }

  ll q = stoi(a);
  for(int i=0; i<q; ++i) x += y;

  ll g = gcd(x, y);
  cout << x/g << " / " << y/g;
  return 0;
}
