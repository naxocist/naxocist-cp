#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s, z; cin >> s; z = s; for(auto &c : s) c = tolower(c); 
  int n = s.size();
  string b = "buu";

  int u = 0, mxu = 0; bool ok = 0, hb = 0;
  for(int i=0; i<n; ++i) {
  	if(ok) {
  		if(s[i] == 'u') mxu = max(mxu, ++u);
  		else ok = 0;
  	}

  	if(i < n-2 and s.substr(i, 3) == b) ok = 1, u = 0;
  	if(s[i] == 'b') hb = 1;
  }

  if(mxu > 0) cout << "Yes" << ' ' << mxu, exit(0);


  if(hb) {
  	bool ok = 0;
  	for(char c : z) {
  		if(ok) cout << 'U';
  		else cout << c;
  		if(tolower(c) == 'b') ok = 1;
  	}
  }else {
  	for(int i=0; i<n; ++i) cout << char(toupper(b[i%3]));
  }
  return 0;
}
