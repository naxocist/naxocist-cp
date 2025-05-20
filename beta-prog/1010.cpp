#include <bits/stdc++.h>
using namespace std;

string s;
char ar[25][25];
int n, m, k;

bool f(int i, int j, int d = 0) {
  if(d == s.size()) return 1;
  if(i < 0 or j < 0 or i >= n or j >= m or ar[i][j] != s[d]) return 0;

  if(k == 0) return f(i, j+1, d+1);
  if(k == 1) return f(i, j-1, d+1);
  if(k == 2) return f(i-1, j, d+1);
  if(k == 3) return f(i+1, j, d+1);
  if(k == 4) return f(i-1, j-1, d+1);
  if(k == 5) return f(i+1, j+1, d+1);
  if(k == 6) return f(i+1, j-1, d+1);
  if(k == 7) return f(i-1, j+1, d+1);

  return 0;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m; 
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j], ar[i][j] = tolower(ar[i][j]);
  int q; cin >> q;
  while(q--) {
    cin >> s;
    for(char &c : s) c = tolower(c);

    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        for(k=0; k<8; ++k) {
          if(f(i, j)) {
            cout << i << ' ' << j << '\n'; goto g;
          }
        }
      }
    }
    g:;
  }
  return 0;
}
