 #include <bits/stdc++.h>
using namespace std;

int i, v, x, l, c;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int k; cin >> k;
  for(int h=1; h<=k; ++h) {
    for(int d=0, n=h; n; n/=10, ++d) {
      int t = n%10;
      if(t <= 3) {
        if(d == 0) i += t;
        if(d == 1) x += t;
        if(d == 2) c += t;
      }

      if(t == 4) {
        if(d == 0) i++, v++;
        if(d == 1) x++, l++;
      }

      if(t == 9) {
        if(d == 0) i++, x++;
        if(d == 1) x++, c++;
      }

      if(5 <= t and t < 9) {
        if(d == 0) v++, i+=t-5;
        if(d == 1) l++, x+=t-5;
      }
    }
  }

  cout << i << ' ' << v << ' ' << x << ' ' << l << ' ' << c;
  return 0;
}
