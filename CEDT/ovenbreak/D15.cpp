#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

bool f(string a, string b) {
  int n = a.size(), m = b.size();
  if(abs(n-m) > 1) return 0;

  if(n == m) {
    int x = 0;
    for(int i=0; i<n; ++i) {
      x += a[i] != b[i];
    }

    return x <= 1;
  }

  for(int i=0; i<min(n, m); ++i) {
    if(a[i] != b[i]) {
      return a.substr(i+1,n-i-1)==b.substr(i,m-i) or a.substr(i,n-i)==b.substr(i+1,m-i-1);
    }
  }

  return 1;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    string a, b; cin >> a >> b;

    if(f(a, b)) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}