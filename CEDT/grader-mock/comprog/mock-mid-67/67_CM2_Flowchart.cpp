#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x, y, z; cin >> x >> y >> z;

  if(x < 50) {
    while(y > z) {
      if(y % 2 == 0) {
        x += y*y + z*z;

        if(x % 10 == 4) {
          break ;
        }

        if(x % 3 == 0) {
          y --;
        }else {
          z ++;
        }

        if(x/(y + z) > 15) break ;
      }else {
        x -= y - z;
        y ++;
      }
    }
  }else {
    if(x > y) {
      if(x % 2 == 0) {
        x *= 2, y = x + 4, z = (y-x)*3;
      }else if(y < z){
        x += y, y = x * 3, z += y;
      }else {
        x /= 2, y *= 2, z = x - y;
      }
    }else {
      if(z % 3 == 2) {
        x = y * 5, y = x / 2, z = y + 7;
      }else if(y > z) {
        x += z, y -= 3, z = x * 2;
      }else {
        x --, y += z, z = y - 4;
      }
    }
  }

  cout << x << ' ' << y << ' ' << z;
  return 0;
}

