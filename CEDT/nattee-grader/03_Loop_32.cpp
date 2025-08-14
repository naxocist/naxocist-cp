#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  string s;
  getline(cin, s);
  for(int i=0; i<t; ++i) {
    getline(cin, s);
    string t;
    for(char c : s) {
      if(c == ' ') continue ;
      t += c;
    }

    s = t;

    if(s[0] != 'R') {
      cout << "WRONG_INPUT" << ln;
      continue ;
    }

    int n = s.size();

    string tmp = ".RYGNBPK";
    int last = 0, score = 0;
    for(int i=0; i<n; i += 2) {
      if(s[i] == 'R' and s[i + 1] == 'R') {
        cout << "WRONG_INPUT" << ln;
        goto g;
      }
      if(s[i] != 'R') break ;
      last = i;
    }

    for(char c : s) score += tmp.find(c);

    if(last + 2 < n) {
      string t = s.substr(last + 2);
      if(t != tmp.substr(2, t.size())) {
        cout << "WRONG_INPUT" << ln;
        goto g;
      }
    }

    cout << score << ln;
    g:;
  }
  return 0;
}

