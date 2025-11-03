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
  int n = s.size();

  if(s == "0") cout << "zero", exit(0);
  
  int k = max(0, 15-n);
  while(k--) s = "0" + s;
  n = s.size();


  string di[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
  string dd[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  string aa[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string tt[] = {"trillion", "billion", "million", "thousand"};

  for(int i=0; i<n; i+=3) {
    string t = s.substr(i, 3);

    bool ok = 0;
    if(t[0] != '0') {
      cout << di[t[0] - '0'] << " ";
      cout << "hundred ";
      ok = 1;
    }

    if(t[1] != '0') {
      ok = 1;
      int x = t[1] - '0';
      int y = t[2] - '0';
      if(x >= 2) {
        cout << dd[x] << " ";
        if(t[2] != '0') {
          cout << di[y] << " ";
        }
      }else {
        // x = 1
        cout << aa[y] << " ";
      }
    }else {
      int y = t[2] - '0';
      if(y) cout << di[y] << " ", ok = 1;
    }


    if(ok && i/3 < 4) cout << tt[i/3] << " ";
  }
  return 0;
}

