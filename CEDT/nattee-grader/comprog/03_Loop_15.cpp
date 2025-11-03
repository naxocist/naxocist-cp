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
  getline(cin, s);

  for(char &c : s) {
    if(c == '(') c = '[';
    else if(c == ')') c = ']';
    else if(c == '[') c = '(';
    else if(c == ']') c = ')';
  }
  cout << s;
  return 0;
}

