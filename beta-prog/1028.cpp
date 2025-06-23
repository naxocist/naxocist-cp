#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  map<char, int> mp;

  while(1) {
    char o, a, b; int x; cin >> o;

    if(o == '!') break ;

    if(o == '=') cin >> a >> x, mp[a] = x;
    else if(o == '#') cin >> a, cout << mp[a] << ln;
    else {
      cin >> a >> b;
      if(o == '+') mp[a] = mp[a] + mp[b];
      if(o == '-') mp[a] = mp[a] - mp[b];
      if(o == '*') mp[a] = mp[a] * mp[b];
      if(o == '/') mp[a] = mp[a] / mp[b];
    }
  }

  cout << '!';
  return 0;
}
