#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int h; char c; cin >> h >> c;

  for(int i=0; i<h; ++i) {
    for(int j=0; j<2*h; ++j) {
      int l = h-1-i, r = h+i;
      if(j == l) cout << "/";
      else if(j == r) cout << "\\";
      else if(l < j and j < r) cout << c;
      else cout << " ";
    }
    cout << ln;
  }
  return 0;
}