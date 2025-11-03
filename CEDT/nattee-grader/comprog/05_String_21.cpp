#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int f(char c) {
  if(isdigit(c)) return 1;
  return 2;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;

  int k = 0;
  bool first = true;
  int n = s.size();

  if(isdigit(s[n-1])) s += 'a';
  else s += '1';


  n ++;
  for(int i=1; i<n; ++i) {
    if((( isalpha(s[i]) and islower(s[i])) or isdigit(s[i]) ) and f(s[i]) == f(s[i-1])) continue ;

    if(!first) cout << ", "; first = false;

    cout << s.substr(k, i-k);
    k = i;
  }

  return 0;
}

