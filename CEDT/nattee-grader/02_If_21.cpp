#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;

  double x = stoll(s);
  double r;
  if(s.size() > 9) {
    x /= 1e9;
    
    if(s.size() > 10) {
      cout << round(x) << 'B';
      return 0;
    }
    x = round(x*10)/10.0;
    cout << x << 'B';
  }else if(s.size() > 6) {
    x /= 1e6;

    if(s.size() > 7) {
      cout << round(x) << 'M';
      return 0;
    }

    x = round(x*10)/10.0;
    cout << x << 'M';
  }else if(s.size() > 3) {
    x /= 1e3;
    if(s.size() > 4) {
      cout << round(x) << 'K';
      return 0;
    }

    x = round(x*10)/10.0;
    cout << x << 'K';
  }else {
    cout << s;
  }
  return 0;
}
