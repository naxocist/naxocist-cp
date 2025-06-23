#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; cin >> n;

  int x = 0, y = 0, di = 1;
  while(n--) {
    string o; int d; cin >> o >> d;
    if(o == "LT") di--;
    if(o == "RT") di++;
    if(o == "BW") di+=2;
    di = (di+4)%4;

    if(di == 0) y += d;
    if(di == 1) x += d;
    if(di == 2) y -= d;
    if(di == 3) x -= d;

    auto ok = [&](int a) {
      return -5e4 < a and a < 5e4;
    };

    if(ok(x) and ok(y)) continue ;

    cout << "DEAD";
    return 0;
  }

  char p[] = {'N', 'E', 'S', 'W'};
  cout << x << ' ' << y << '\n' << p[di];
  return 0;
}
