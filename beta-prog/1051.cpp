#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int n, m; cin >> n >> m;

    vector<vector<int>> a, b;
    while(n--) {
      int x; cin >> x;
      a.pb(vector<int>()); string s;
      while(x--) cin >> s, a.back().pb((s[1] - 'a' + 1) * (s[0] == '-' ? -1 : 1));
    }

    while(m--) {
      int x; cin >> x;
      b.pb(vector<int>()); string s;
      while(x--) cin >> s, b.back().pb((s[1] - 'a' + 1) * (s[0] == '-' ? -1 : 1));
    }


    auto f = [&](vector<vector<int>> &x, int i) {
      for(auto &cl : x) {
        bool t = 0;
        for(auto &y : cl) {
          bool h = i&(1<<(abs(y) - 1)) ? 1 : 0;
          if(y < 0) h = !h;
          if(h) t = 1;
        }
        if(!t) return 0;
      }
      return 1;
    };

    for(int i=0; i<(1<<17); ++i) {
      if(f(a, i) and !f(b, i)) {
        cout << "NO\n";
        goto g;
      }
    }
    cout << "YES\n";
    g:;
  }
  return 0;
}