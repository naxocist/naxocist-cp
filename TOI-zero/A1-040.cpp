#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int s = 0;
  while(1) {
    int x; cin >> x; if(x == 5) break ;
    if(x == 1) s += 100;
    if(x == 2) s += 120;
    if(x == 3) s += 200;
    if(x == 4) s += 60;
  }

  cout << "Bye Bye\n" << "Total Calories: " << s;
  return 0;
}
