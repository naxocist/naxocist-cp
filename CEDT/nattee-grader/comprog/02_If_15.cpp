#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;

  string NO = "Not a mobile number";
  string YES = "Mobile number";
  if(s.size() != 10) {
    cout << NO;
    return 0;
  }

  if(s[0] != '0') {
    cout << NO;
    return 0;
  }

  if(s[1] != '6' and s[1] != '8' and s[1] != '9') {
    cout << NO;
    return 0;
  }

  cout << YES;

  return 0;
}
