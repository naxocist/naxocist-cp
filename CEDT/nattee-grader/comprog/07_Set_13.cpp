#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  set<string> s;
  set<string> lose;
  string a, b; 
  while(cin >> a >> b) {
    s.insert(a); s.insert(b);
    lose.insert(b);
  }

  bool ok = 1;
  for(string z : s) {
    if(lose.find(z) == lose.end()) cout << z << ' ', ok = 0;
  }

  if(ok) cout << "None";
  return 0;
}

