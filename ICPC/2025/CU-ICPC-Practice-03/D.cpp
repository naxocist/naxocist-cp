#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  int mx = 0, idx = 0;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    x = (x + m - 1)/m;
    if(x > mx) {
      mx = x, idx = i;
    }else if(x == mx) {
      idx = i;
    }
  }

  cout << idx+1;
}


