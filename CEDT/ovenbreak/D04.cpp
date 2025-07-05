#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  string s;
  getline(cin >> ws, s);
  for(char c : s) {
    if(!isalpha(c)) cout << c;
    else {
      int k = tolower(c) - 'a';
      k -= n,k+=26,k %= 26;
      if(isupper(c)) cout << char(k+'A');
      else cout << char(k+'a');
    }
  }
  return 0;
}