#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int ar[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> ar[i][j];
  int mx = INT_MIN;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      int s = 0;
      for(int k=0; i+k<n and j+k<n; ++k) {
        s += ar[i+k][j+k];
        mx = max(mx, s);
      }
    }
  }

  cout << mx;
  return 0;
}
