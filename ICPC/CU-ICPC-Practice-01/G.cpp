#include <bits/stdc++.h>
using namespace std;

const int M = 103, S = 903, INF = 2e9;
string dp[M][S], dp2[M][S];

string f(string a, string b, int k) {
  b += k + '0';
  if(a == "-") return b;
  if(a.size() != b.size()) return a.size() < b.size() ? b : a;

  for(int i=0; i<a.size(); ++i) {
    if(a[i] > b[i]) return a;
    else if(a[i] < b[i])return b;
  }

  return a;
}

string f2(string a, string b, int k) {
  b += k + '0';
  if(a == "-") return b;
  if(a.size() != b.size()) return a.size() > b.size() ? b : a;

  for(int i=0; i<a.size(); ++i) {
    if(a[i] < b[i]) return a;
    else if(a[i] > b[i]) return b;
  }

  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, s; cin >> m >> s;

  for(int i=0; i<=m; ++i) for(int j=0; j<=s; ++j) dp[i][j] = "-", dp2[i][j] = "-";

  dp[0][0] = dp2[0][0] = "0";
  for(int i=0; i<=9; ++i) dp[1][i] = dp2[1][i] = i + '0';

  for(int i=2; i<=m; ++i) {
    for(int j=0; j<=s; ++j) {
      for(int k=0; k<=9; ++k) {
        if(j-k < 0) continue ;
        if(dp[i-1][j-k] != "0" and dp[i-1][j-k] != "-") 
          dp[i][j] = f(dp[i][j], dp[i-1][j-k], k);

        if(dp2[i-1][j-k] != "0" and dp2[i-1][j-k] != "-") 
          dp2[i][j] = f2(dp2[i][j], dp2[i-1][j-k], k);
      }
    }
  }

  if(dp[m][s] == "-") cout << "-1 -1";
  else cout << dp2[m][s] << ' ' << dp[m][s];
  return 0;
}
