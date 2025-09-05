#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  vector<string> mp = {"soon", "neung", "song", "sam", "si", "ha", "hok", "chet", "paet", "kao", "et", "yi", "sip", "roi", "phan", "muen", "saen", "lan"};
  vector<int> val = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 10, 100, 1000, 10000, 100000, 1000000};

  assert(val.size() == mp.size());

  string s;
  while(getline(cin, s)) {
    if(s == "q") break ;

    s += ' ';
    vector<int> part;
    int p = 0;
    for(int i=0; i<(int)s.size(); ++i) {
      if(s[i] == ' ') {
        string t = s.substr(p, i-p);
        int v = val[find(all(mp), t) - begin(mp)];
        part.pb(v);
        p = i + 1;
      }
    }

    int n = part.size(), c = 0;
    int res = 0;
    for(int i=n-1; i>=0; ) {
      if(i > 0 and part[i-1] <= 9) {
        res += part[i]*part[i-1]; i-= 2;
      }else res += part[i], i--;
    }

    cout << res << ln;
  }

  return 0;
}

