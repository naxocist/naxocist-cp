#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  string s; 
  while(getline(cin, s)) {

    int n = s.size();
    int p = -1;

    string res;
    for(int i=0; i<n; ++i) {
      if(s[i] != s[n-1]) continue ;
      if(p == -1) p = i;
      else res += s.substr(p+1, i-p-1), p = -1;
    }

    cout << res << '\n';
  }
  return 0;
}

