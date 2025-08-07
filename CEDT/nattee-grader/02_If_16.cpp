#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  if(x > 0) cout << "positive";
  else if(x < 0) cout << "negative";
  else cout << "zero";

  cout << ln;
  
  if(x&1) cout << "odd";
  else cout << "even";
  return 0;
}
