#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;

  string s;
  while(x) {
  	if(x >= 1000) x -= 1000, s += "M";
  	else if(x >= 900) x -= 900, s += "CM";
  	else if(x >= 500) x -= 500, s += "D";
  	else if(x >= 400) x -= 400, s += "CD";
  	else if(x >= 100) x -= 100, s += "C";
  	else if(x >= 90) x -= 90, s += "XC";
  	else if(x >= 50) x -= 50, s += "L";
  	else if(x >= 40) x -= 40, s += "XL";
  	else if(x >= 10) x -= 10, s += "X";
  	else if(x >= 9) x -= 9, s += "IX";
  	else if(x >= 5) x -= 5, s += "V";
  	else if(x == 4) x = 0, s += "IV";
  	else x--, s += "I";
  }

  cout << s;
  return 0;
}
