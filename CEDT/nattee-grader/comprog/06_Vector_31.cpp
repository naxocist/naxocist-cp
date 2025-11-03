#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

const int n = 5;
string ar[n][n], mp[n][n];


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string t; getline(cin, t);

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cin >> ar[i][j];
      mp[i][j] = ar[i][j];
    }
  }

  int k = 0;
  string bingo = "BINGO";
  while(cin >> t) {
    k ++;
    int c = find(all(bingo), t[0]) - begin(bingo);
    string val = t.substr(1);

    for(int r=0; r<n; ++r) {
      if(val == ar[r][c]) {
        ar[r][c] = "*";

        bool row = 1;
        for(int j=0; j<n; ++j)  if(ar[r][j] != "*") row = 0;

        bool col = 1;
        for(int i=0; i<n; ++i) if(ar[i][c] != "*") col = 0;

        bool diag1 = 0;
        if(r - c == 0) {
          diag1 = 1;
          for(int i=0; i<n; ++i) if(ar[i][i] != "*") diag1 = 0;
        }

        bool diag2 = 0;
        if(r + c == n - 1) {
          diag2 = 1;
          for(int i=0; i<n; ++i) if(ar[i][n-i-1] != "*") diag2 = 0;
        }

        if(row or col or diag1 or diag2) {
          cout << k << ln;

          if(row) {
            for(int j=0; j<n; ++j) {
              if(mp[r][j] == "*") continue ;
              if(j) cout << ", ";
              cout << bingo[j] << mp[r][j];
            }
            cout << ln;
          }

          if(col) {

            for(int i=0; i<n; ++i) {
              if(mp[i][c] == "*") continue ;
              if(i) cout << ", ";
              cout << bingo[c] << mp[i][c];
            }
            cout << ln;
          }

          if(diag1) {
            for(int i=0; i<n; ++i) {
              if(mp[i][i] == "*") continue ;
              if(i) cout << ", ";
              cout << bingo[i] << mp[i][i];
            }
            cout << ln;

          } 

          if(diag2) for(int i=n-1; i>=0; --i) {
            if(mp[i][n-i-1] == "*") continue ;
            if(i!=n-1) cout << ", ";
            cout << bingo[n-i-1] << mp[i][n-i-1];
          }
          goto g;
        }


      }
    }
  }
  g:;

  return 0;
}

