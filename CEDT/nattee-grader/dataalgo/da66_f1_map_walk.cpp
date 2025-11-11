#include <bits/stdc++.h>
using namespace std;
int n, m;
bool no[11][11];
bool vis[11][11];
string res;

void f(int i, int j) {
  if(i < 1 or j < 1 or i > n or j > m or no[i][j] or vis[i][j]) return ;
  if(i == n and j == m) {
    cout << res << '\n';
    return ;
  }

  vis[i][j] = 1;

  res += 'A';
  f(i,j+1); 
  res.pop_back();
  res += 'B';
  f(i+1,j);
  res.pop_back();
  res += 'C';
  f(i-1,j);
  res.pop_back();

  vis[i][j] = 0;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) cin >> no[i][j];
  }

  f(1,1);
  cout << "DONE";
  return 0;
}
