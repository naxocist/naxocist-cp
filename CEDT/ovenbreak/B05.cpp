#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string n, m; cin >> n >> m;
  ll a, b, c; cin >> a >> b >> c;
  ll x, y, z; cin >> x >> y >> z;

  ll s = a + b + c, ss = x + y + z;
  if(s != ss) {
    cout << "Win: ";
    if(s > ss) cout << n;
    else cout << m;
    return 0;
  }

  if(a != x) {
    cout << "Win: ";
    if(a > x) cout << n;
    else cout << m;
    return 0;
  }

  if(c != z) {
    cout << "Win: ";
    if(c > z) cout << n;
    else cout << m;
    return 0;
  }

  if((n[2] == '3') ^ (m[2] == '3')) {
    cout << "Win: ";
    if(n[2] == '3') cout << n;
    else cout << m;
    return 0;
  }

  if((n.substr(8, 2) == "21") ^ (m.substr(8, 2) == "21")) {
    cout << "Win: ";
    if(n.substr(8, 2) == "21") cout << n;
    else cout << m;
    return 0;
  }

  if(n[0] != m[0]) {
    cout << "Win: ";
    if(n[0] < m[0]) cout << n;
    else cout << m;
    return 0;
  }

  if(n[1] != m[1]) {
    cout << "Win: ";
    if(n[1] < m[1]) cout << n;
    else cout << m;
    return 0;
  }

  cout << "No one.";
  return 0;
}