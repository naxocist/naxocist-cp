#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string id1; double g1; char c1, cal1, cal2;
  cin >> id1 >> g1 >> c1 >> cal1 >> cal2;

  string id2; double g2; char c2, cal3, cal4;
  cin >> id2 >> g2 >> c2 >> cal3 >> cal4;

  bool p1 = c1 == 'A' and cal1 <= 'C' and cal2 <= 'C';
  bool p2 = c2 == 'A' and cal3 <= 'C' and cal4 <= 'C';

  if(p1 and p2) {

    if(g1 != g2) {
      if(g1 > g2) cout << id1;
      else cout << id2;
      return 0;
    }

    if(cal1 != cal3) {
      if(cal1 > cal3) cout << id2;
      else cout << id1;
      return 0;
    }

    if(cal2 != cal4) {
      if(cal2 > cal4) cout << id2;
      else cout << id1;
      return 0;
    }

    cout << "Both";

  }else if(p1) cout << id1;
  else if(p2) cout << id2;
  else cout << "None";
  return 0;
}
