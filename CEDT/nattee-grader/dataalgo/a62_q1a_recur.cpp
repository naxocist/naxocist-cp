#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int ar[1<<N][1<<N];

void f(int a, int b, int tp, int lf) {
  if(a == 0) return void(ar[tp][lf] = b);
  f(a-1,b,tp,lf);
  f(a-1,b-1,tp,lf+(1<<(a-1)));
  f(a-1,b+1,tp+(1<<(a-1)),lf);
  f(a-1,b,tp+(1<<(a-1)),lf+(1<<(a-1)));
}

int main() {
  int a, b; cin >> a >> b;
  f(a,b,0,0);
  for(int i=0; i<1<<a; ++i) for(int j=0; j<1<<a; ++j) cout << ar[i][j] << " \n"[j == (1<<a)-1];
  return 0;
}
