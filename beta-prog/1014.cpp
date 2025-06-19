#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int w, h, n; cin >> w >> h >> n;

  vector<int> v(4e3 + 2);
  while(n--){ 
    int x, l; cin >> x >> l;
    v[x] ++, v[x+l]--;
  }

  int a = 0, b = 0;
  for(int i=0; i<w; ++i) v[i] += v[i-1], a += v[i] == 0, b += v[i] == 1;
  cout << a*h << ' ' << b*h;
  return 0;
}
