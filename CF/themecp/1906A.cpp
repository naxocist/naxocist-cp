#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back
const int n = 3;
char ar[n][n];

using pi = pair<int, int>;

int adj(pi A, pi B) {
  return max(abs(A.first - B.first), abs(A.second - B.second)) == 1;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) cin >> ar[i][j];
  }

  string res = "CCC";
  for(int a=0; a<n; ++a) {
    for(int b=0; b<n; ++b) {
      for(int c=0; c<n; ++c) {
        for(int d=0; d<n; ++d) {
          for(int e=0; e<n; ++e) {
            for(int f=0; f<n; ++f) {
              pi A = pi(a, b), B = pi(c, d), C = pi(e, f);
              if(A == B or B == C or A == C) continue ;

              if(!adj(A,B) or !adj(B,C)) continue ;

              char x = ar[a][b], y = ar[c][d], z = ar[e][f];
              string r; r += x, r += y, r += z;
              res = min(res, r);
            }
          }
        }
      }
    }
  }

  cout << res;
  return 0;
}
