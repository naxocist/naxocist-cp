#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;

  string z;
  int res = 0;
  while(cin >> z) {
    int n = z.size();
    for(int i=0; i<n; ++i) {
      if(i + s.size() - 1 >= n) break ;
      string t = z.substr(i, s.size());

      if(i and isalpha(z[i-1])) continue ;
      if(i + s.size() < n and isalpha(z[i+s.size()])) continue ;
      if(t == s) res ++;
    }
    
  }

  cout << res;
  return 0;
}

