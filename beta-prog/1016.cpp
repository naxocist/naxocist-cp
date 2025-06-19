#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  double x = 0, y = 0;
  int d; char mv[10];
  while(scanf("%d%s", &d, mv)) {
    for(int i=0; i<strlen(mv); ++i) {
      double diag = sqrt(0.5) * d;
      bool t = strlen(mv) == 2;
      switch (mv[i]){
        case 'N':
          y+=t ? diag : d; break;
        case 'S':
          y-=t ? diag : d; break;
        case 'E':
          x+=t ? diag : d; break;
        case 'W':
          x-=t ? diag : d; break;
      }
    }
  }

  printf("%.3f %.3f\n%.3f", x, y, sqrt(x*x + y*y));

  return 0;
}
