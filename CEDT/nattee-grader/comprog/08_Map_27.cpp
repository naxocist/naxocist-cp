#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  map<string, char> mp;
  map<char, string> rv;
  mp["0"] = ' '; rv[' '] = "0";

  int base = 1;
  int k;
  for(int i=0; i<26; ++i) {
    char c = 'a' + i;
    if(c < 'p') base += i % 3 == 0, k = i % 3 + 1;
    else if(c == 'p' || c == 't' || c == 'w') k = 1, base ++;
    else k ++;


    string t; int p = k; while(p--) t += base + '0';
    mp[t] = c;
    rv[c] = t;
  }

  string o; string s;
  while(cin >> o) {
    cin.ignore();
    getline(cin, s);
    cout << ">> ";
    if(o == "T2K") {
      for(char c : s) {
        c = tolower(c);
        if(!isalpha(c) && c != ' ') continue ;
        cout << rv[c] << ' ';
      }
      cout << ln;
    }else {
      s += ' ';
      int p = 0;
      for(int i=0; i<(int)s.size(); ++i) {
        if(s[i] == ' ') {
          string t = s.substr(p, i-p);
          cout << mp[t];
          p = i + 1;
        }
      }
      cout << ln;
    }
  }
  return 0;
}

