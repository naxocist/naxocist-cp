#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  map<string, string> s, z;
  while(n--) {
    string a, b, c; cin >> a >> b >> c;
    s[a + " " + b] = c;
    s[c] = a + " " + b;
  }

  int m; cin >> m; cin.ignore();
  while(m--) {
    string a; getline(cin, a);
    cout << a << " --> ";
    if(s.find(a) != s.end()) cout << s[a];
    else if(z.find(a) != z.end()) cout << z[a];
    else cout << "Not found";
    cout << ln;
  }
  return 0;
}

