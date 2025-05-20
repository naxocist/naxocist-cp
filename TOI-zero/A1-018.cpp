#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  if(x < 0) cout << "Error : Please input positive number", exit(0);

  if(x > 9 or x == 0) cout << "Error : Out of range", exit(0);

  if(x <= 3) while(x--) cout << "I";
  else if(x == 4) cout << "IV";
  else if(x == 9) cout << "IX";
  else {
    cout << "V"; x -= 5; while(x--) cout << "I";
  }
  return 0;
}
