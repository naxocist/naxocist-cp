#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  ll n; cin >> n;

  char c; int x;
  ll s = 0;
  string t;
  while(cin >> t) {
    t = t.substr(1);
    s += stoi(t);
  }
  cout << s*n;
  return 0;
}

