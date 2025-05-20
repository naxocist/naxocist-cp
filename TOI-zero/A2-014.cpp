#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  if(n > m) swap(a, b), swap(n, m);

  string t = "love", res;
  int w, r, mxr; w = r = mxr = 0;
  for(int i=0; i<m; ++i) {
  	a[i] = tolower(a[i]), b[i] = tolower(b[i]);
  	if(t.find(a[i%n]) != string::npos or t.find(b[i]) != string::npos) {
  		res += 'w';
  		w++, r++; mxr = max(mxr, r);
  	}else {
  		res += '$';
  		r = 0;
  	}
  }


  if(w&1) res += to_string(mxr);
  else if(mxr < 2) res += '#';

  cout << res;
  return 0;
}
