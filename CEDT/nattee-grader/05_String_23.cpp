#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  string s; cin >> s;
  int k; cin >> k;

  reverse(all(s));

  while(k--){
    int carry = 0;

    string t;
    for(int i=0; i<s.size(); ++i) {
      if(s[i] == '-') {
        t += '-';
        continue ;
      }

      if(isdigit(s[i])) {
        int x = s[i] - '0' + (i == 0) + carry;
        carry = x / 10; x %= 10;
        t += x + '0';
      }else {
        int x = s[i] - 'A' + (i == 0) + carry;
        carry = x / 26; x %= 26;
        t += x + 'A';
      }
    }

    s = t;
  }
  reverse(all(s));

  cout << s;
  return 0;
}

