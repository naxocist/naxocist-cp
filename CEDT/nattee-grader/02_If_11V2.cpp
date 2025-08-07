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

  if(s.size() != 2 or !isdigit(s[0]) or !isdigit(s[1])) {
    cout << "Error";
    return 0;
  }

  int x = stoi(s);
  if(x == 1 or x == 2 or (20 <= x and x <= 29) or (30 <= x and x <= 39) or x == 40 or x == 51 or x == 53 or x == 55 or x == 58) {
    cout << "OK";
  }else cout << "Error";
  return 0;
}
