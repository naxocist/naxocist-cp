#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e6 + 1;
int no[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int a, x, y; cin >> a >> x >> y;
    if(abs(x-y) < abs(a-x) + abs(a-y)) cout << "YES";
    else cout << "NO";
    cout << ln;
  }
  return 0;
}

