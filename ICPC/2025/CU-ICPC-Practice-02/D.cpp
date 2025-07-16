#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e5 + 3;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int px = -1, mx = INT_MIN;
  int res = 0;
  while(n--){
    int x, h; cin >> x >> h;
    if(x-h>mx) mx=x, res ++;
    else if(x>mx) mx=x+h, res ++;
    else if(x-h>px) mx=x;
    else mx=x+h;
    px = x;
  }

  cout << res;
  return 0;
}