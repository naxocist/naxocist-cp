#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  map<string, int> mp;
  int mx = 0; string mxr;
  char c;
  while(cin >> c) {

    string s;
    if(c == 'K' or c == 'P') cin >> s;

    if(c == 'K') {
      if(++mp[s] > mx) mx = mp[s], mxr = s;
    }else if(c == 'P') {
      if(mp.find(s) != mp.end()) cout << mp[s] << ln;
      else cout << 0 << ln;
    }else if(c == 'H') {
      cout << mxr << ln;
    }else if(c == 'N') {
      cout << mp.size() << ln;
    }else break ;
  }
  return 0;
}

