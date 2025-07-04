#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int sp = 1;
  while(n--) {
    string s; cin >> s;
    if(s == "oii") {
      int i = 0;
      string t;
      for(;;) {
        char c; cin >> c;
        t += c;
        if(c == 'i') i ++;
        else i = 0;
        if(i == 3) break ;
      }

      t = t.substr(0, t.size()-3);
      for(char c : t) {
        int k = sp;
        while(k--) cout << c << ' ';
      }
      continue ;
    }

    int i = 0;
    for(;;) {
      char c; cin >> c;
      if(c == 'a') sp ++;
      if(c == 'o') sp --;
      sp = max(sp, 1);
      i += c == 'i';
      if(i == 3) break ;
    }
  }
  return 0;
}