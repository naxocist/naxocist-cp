#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  
  string mp[] = {"UUUU", "UUUL", "UULU", "UULL", "ULUU", "ULUL", "ULLU", "ULLL", "LUUU", "LUUL", "LULU", "LULL"};
  int val[] = {0,1,2,3,4,5,6,7,8,9,10,11};

  string s; getline(cin, s);
  int m = s.size();

  char o; string t;
  while(cin >> o) {
    cin.ignore(); getline(cin, t);

    if(o == 'D') {
      string z;
      for(char c : t) if(isalpha(c)) z += isupper(c) ? 'U' : 'L';
      int n = z.size();

      for(int i=0; i<n; i+=4) {
        string r = z.substr(i, 4);
        int k = 0; while(mp[k] != r) k++;
        int v = val[k];

        if(v < 10) cout << v;
        else if(v == 10) cout << '-';
        else cout << ',';
      }
    }else {
      string z;

      int d = 0;
      for(char c : t) {
        string r;
        if(c == '-') r = mp[10];
        else if(c == ',') r = mp[11];
        else r = mp[c - '0'];

        for(char f : r) {
          while(d < m and !isalpha(s[d])) {
            cout << s[d];
            d = (d + 1) % m;
          }
          char j;
          if(f == 'U') j = toupper(s[(d++)%m]);
          else j = tolower(s[(d++)%m]);
          cout << j;
        }
      }

    }

    cout << ln;
  }
  return 0;
}

