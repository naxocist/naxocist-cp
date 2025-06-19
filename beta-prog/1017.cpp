#include <bits/stdc++.h>
using namespace std;

int ar[20][20], cnt[101];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  bool ok = 1;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
    cin >> ar[i][j];
    if(cnt[ar[i][j]]++) ok = 0;
  }

  int s = accumulate(ar[0], ar[0]+n, 0);
  for(int i=0; i<n; ++i) if(accumulate(ar[i], ar[i]+n, 0) != s) ok = 0;

  for(int j=0; j<n; ++j) {
    int t = 0;
    for(int i=0; i<n; ++i) t += ar[i][j];
    if(t != s) ok = 0;
  }

  int t = 0;
  for(int i=0,j=0; i<n; i++, j++) t += ar[i][j];
  if(t != s) ok = 0;

  t = 0;
  for(int i=0,j=n-1; i<n; i++, j--) t += ar[i][j];
  if(t != s) ok = 0;

  cout << (ok ? "Yes" : "No");
  return 0;
}
