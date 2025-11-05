#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k, d; cin >> n >> k >> d;

  vector<int> v(n);
  for(int i=0; i<n; ++i) {
    int x; cin >> x; v[i] = x;
  }

  v.insert(v.begin() + k, d);
  n ++;

  int l = k, r = k;
  int a = -1, b = -1;
  int in = 0;
  while(1) {
    while(l-1 >= 0 && v[l-1] == d) l --;
    while(r+1 < n && v[r+1] == d) r ++;

    if(r-l+1-in >= 3) {
      a = l; b = r;
      if(l-1 >= 0 && r+1 < n && v[l-1] == v[r+1]) {
        d = v[r+1];
        in = r-l+1;
        l--, r ++;
        continue ;
      }
      break ;
    }
    break ;
  }

  for(int i=0; i<n; ++i) {
    if(a <= i && i <= b) continue ;
    cout << v[i] << ' ';
  }

  return 0;
}
