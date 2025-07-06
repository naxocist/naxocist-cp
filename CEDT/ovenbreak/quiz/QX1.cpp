#include <bits/stdc++.h>
using namespace std;

int main() {
  int x; cin >> x;
  if(x == 1) {
    double a, b; cin >> a >> b;
    long long res = a*b;
    cout << res;
  }else if(x == 2) {
    int t; cin >> t;

    if(t > 84) cout << "A";
    else if(t > 79) cout << "B+"; 
    else if(t > 74) cout << "B";
    else if(t >= 70) cout << "C+";
    else if(t > 65) cout << "C";
    else if(t > 59) cout << "D+";
    else if(t >= 50) cout << "D";
    else cout << "F";

  }else if(x == 3) {
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
      int k = i;while(k--) cout << "*";
      if(i%3 == 0 or i%11 == 0) cout << " Ti amo";
      cout << '\n';
    }
  }else {
    int n; cin >> n;
    vector<int> v(n); for(auto &x : v) cin >> x;
    int k; cin >> k;

    int res = 0;
    for(auto x : v) res += x == k;
    cout << res;
  }
  return 0;
}