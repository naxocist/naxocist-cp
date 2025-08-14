#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double p; cin >> p;
  double t = 1, k = 0;
  do {
    k ++;
    t = t*(365 - k + 1)/365;
  } while(1-t < p);

  cout << k;
  return 0;
}

