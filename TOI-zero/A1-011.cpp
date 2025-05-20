#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  int ar[26] {};

  for(char c : s) ar[c - 'A']++; 

  for(int i=0; i<s.size(); ++i) {
    if(i == 0 or s[i] != s[i-1]) cout << ar[s[i] - 'A'] << s[i];
  }
  return 0;
}
