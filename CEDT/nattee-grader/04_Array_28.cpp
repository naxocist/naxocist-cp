#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; getline(cin, s);

  int ar[26] = {};
  for(char c : s) {
    if(isalpha(c)) {
      c = tolower(c);
      ar[c-'a'] ++;
    }
  }

  for(int i=0; i<26; ++i) {
    if(!ar[i]) continue ;
    cout << char('a' + i) << " -> " << ar[i] << ln;
  }
  return 0;
}

