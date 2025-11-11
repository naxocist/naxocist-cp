#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;

  for(int i=0; i<(1<<n); ++i) {
    int con = 0, mx = 0;
    string s;
    for(int j=n-1; j>=0; --j) {
      if(i&(1<<j)) mx = max(mx, ++con), s += '1';
      else con = 0, s += '0';
    }
    if(mx >= k) cout << s << '\n';
  }
  return 0;
}
