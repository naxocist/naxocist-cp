#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  int q; cin >> q;
  while(q--) {
    int l, r; cin >> l >> r;
    string t = s.substr(l,r-l+1);
    for(int i=0,j=t.size()-1; i<j; ++i, --j) {
      if(t[i] != t[j]) {
        cout << t << ": No\n";
        goto g;
      }
    }

    cout << t << ": Yes\n";
    g:;
  }
  return 0;
}