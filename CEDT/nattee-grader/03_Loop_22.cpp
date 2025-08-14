#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int t = 2;

  bool first = 1;
  while(n != 1) {
    int cnt = 0;
    while(n % t == 0) cnt ++, n/=t;

    while(cnt--) {
      if(!first) cout << "*";
      cout << t;
      first = 0;
    }
    t ++;
  }

  return 0;
}

