#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  int n = s.size();

  string res;
  for(int i=n-1, j=0; i>=0; --i, ++j) {
  	if(j%3 == 0 and j) res += ",";
  	res += s[i];
  }
  reverse(all(res));
  cout << res;
  return 0;
}
