#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int ar[n], s = 0;
  for(int i=0; i<n; ++i) {
  	int x, y; cin >> x >> y; ar[i] = max(x, y); s += ar[i];
  }

  for(int i=0; i<n and n > 1; ++i) {
  	if(i) cout << " + ";
  	cout << ar[i];
  }

  if(n > 1) cout << " = ";

  cout << s;
  return 0;
}
