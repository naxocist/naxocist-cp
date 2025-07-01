#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  int x = ceil(sqrt(a)), y = ceil(sqrt(b));
  int ar = x*x-a, br = y*y-b;
  int al = x-ar-1, bl = y-br-1;

  if(x == y) cout << a-b, exit(0);

  int v = max(0,x-y-1)*2 + 1 + (ar%2==0);
  if(al >= bl-(bl%2) and ar >= br-(br%2)) {
    v += br%2; 
    cout << v;
    return 0;
  }

  int h = min(abs(al-(al%2)-bl), abs(ar-(ar%2)-br));
  cout << v + h;
  return 0;
}
