#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
#define int ll

int under(int a, int b) {
  int n; cin >> n;
  int x = 1;
  while(x*x < n) x ++;

  if(x == 1) cout << 0;
  else if(x <= 2) cout << x-1 + (n != 3);
  else cout << 2*x-3 + (n-x+1)%2; 
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  int x = ceil(sqrt(a)), y = ceil(sqrt(b));

  int lx = a - (x-1)*(x-1) - 1, rx = x*x - a;
  int ly = b - (y-1)*(y-1) - 1, ry = y*y - b;

  if(x == y) cout << a-b, exit(0);

  int gap = max(0LL, x-y-1);
  if(lx >= ly-(ly%2) and rx >= ry-(ry%2)) {
    int v = 2*gap + 1 + (rx%2 == 0) + (ry%2);
    cout << v;
    return 0;
  }

  int v = 2*gap + 1 + (rx%2 == 0);
  cout << v + min(abs(lx-(lx%2)-ly), abs(rx-(rx%2)-ry));
  return 0;
}
