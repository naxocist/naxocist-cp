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
  string res;
  while(cin >> s) {
    if(s == "END") break ;

    reverse(all(s));
    int n = s.size();
    string t;

    int carry = 0;
    for(int i=0; i<max(res.size(), s.size()); ++i) {
      if(i >= res.size()) res += '0';
      if(i >= s.size()) s += '0';

      int k = s[i] + res[i] - '0' - '0' + carry;
      int x = k%10; carry = k/10;
      t += x + '0';
    }

    if(carry) t += carry + '0';

    res = t;
  }

  reverse(all(res));
  cout << res;
  return 0;
}

