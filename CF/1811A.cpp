#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  while(q--) {
    int n, d; string s; cin >> n >> d >> s;
    bool ok = 1;
    for(int i=0; i<n; ++i) {
      if(s[i]-'0'<d and ok and d) {
        ok = 0;
        cout << d;
      }
      cout << s[i];
    }

    if(ok or !d) cout << d;
    cout << '\n';
  }
  return 0;
}
