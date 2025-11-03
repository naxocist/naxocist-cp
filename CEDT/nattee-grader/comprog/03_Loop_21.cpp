#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s;
  while(cin >> s) {
    int n = s.size();

    bool a = 0, A = 0, d = 0, p = 0;
    for(char c : s) {
      if(islower(c)) a = 1;
      else if(isupper(c))  A = 1;
      else if(isdigit(c)) d = 1;
      else p = 1;
    }

    cout << ">> ";
    if(n >= 12 and a and A and d and p) cout << "strong";
    else if(n >= 8 and a and A and d) cout << "weak";
    else cout << "invalid";
    cout << ln;
  }
  return 0;
}

