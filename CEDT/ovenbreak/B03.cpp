#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  if(x >= 85) cout << "A";
  else if(x >= 80) cout << "B+";
  else if(x >= 75) cout << "B";
  else if(x >= 70) cout << "C+";
  else if(x >= 65) cout << "C";
  else if(x >= 60) cout << "D+";
  else if(x >= 50) cout << "D";
  else cout << "F";

  return 0;
}