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

  int t = 0;
  for(int i=0; i<s.size(); ++i) {
    t += (13-i)*(s[i]-'0');

    cout << s[i];
    if(i == 0 or i == 4 or i == 9 or i == 11) cout << "-";
  }

  t %= 11;
  t = 11 - t; 
  t %= 10;
  cout << t;
  return 0;
}