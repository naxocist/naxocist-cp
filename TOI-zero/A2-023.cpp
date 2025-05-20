#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s; int n = s.size();
  for(char &c : s) c = tolower(c), c = (c == 'i' or c == 't' ? 'x' : c);

  bool chk = true, ok = true;
  int a = 0, mxa = 0;
  for(int i=0; i<n; ++i) {
    char c = s[i];

    if(c != 'x') chk = false;

    if(c == 'a') a ++, mxa = max(mxa, a);
    else a = 0;

    if(c == 'a' and i-1 > 0 and s[i-1] != 'r' and s[i-1] != 'a') cout << "no " << i, exit(0);
    if(c == 'r') {
      if(i == n-1) cout << "no " << i, exit(0);
      if(s[i+1] != 'a') cout << "no " << i+1, exit(0);
    }
    if(c == 'b') {
      if(i == n-1) cout << "no " << i, exit(0);
      if(s[i+1] != 'x') cout << "no " << i+1, exit(0);
    }
  }

  if(chk) cout << "unknown " << n;
  else cout << "yes " << mxa;
  return 0;
}

