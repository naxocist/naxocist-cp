#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

set<string> res;
int n;
string s;

void f(int l) {

  if(l == n) {
    res.insert(s);
    return ;
  }

  for(int i=l; i<n; ++i) {
    swap(s[i], s[l]);
    f(l + 1);
    swap(s[i], s[l]);
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> s;
  n = s.size();
  f(0);
  for(auto &x : res) cout << x << ' ';
  return 0;
}

