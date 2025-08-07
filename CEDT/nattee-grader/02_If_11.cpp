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

  if(s.size() != 2) {
    cout << "Error";
    return 0;
  }

  char x = s[0], y = s[1];
  if(!isdigit(x) or !isdigit(y)) {
    cout << "Error";
    return 0;
  }

  int a = x-'0',b = y-'0';


  bool ok = 0;
  if(a == 0) {
    if(b == 1 or b == 2) ok = 1;
  }else if(a == 2) {
    ok = 1;
  }else if(a == 3) {
    ok = 1;
  }else if(a == 4) {
    if(b == 0) ok = 1;
    else ok = 0;
  }else if(a == 5) {
    if(b == 1 or b == 3 or b == 5 or b == 8) ok = 1;
    else ok = 0;
  }else ok = 0;

  if(ok) cout << "OK";
  else cout << "Error";
  return 0;
}
