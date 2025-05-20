#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m, d; cin >> m >> d;
  if(m < 3 or (m == 3 and d < 21)) cout << "winter"; 
  else if(m < 6 or (m == 6 and d < 21)) cout << "spring"; 
  else if(m < 9 or (m == 9 and d < 21)) cout << "summer"; 
  else cout << "fall";
  return 0;
}
