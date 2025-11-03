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

  string ar[n];
  int ct[n];
  for(int i=0; i<n; ++i) cin >> ar[i] >> ct[i];

  string s, p = "";
  int res = 0;
  while(cin >> s) {
    string c = s.substr(4, 2);
    if(c == p) continue ;

    int cost = -1;
    for(int i=0; i<n; ++i) if(c == ar[i]) cost = ct[i];
    if(p != "") res += cost;
    p = c;
  }

  cout << res;
  return 0;
}

