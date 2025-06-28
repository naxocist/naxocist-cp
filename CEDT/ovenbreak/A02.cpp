#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  b += 60*a; d += 60*c;
  int x = d-b; 
  if(x < 0) x += 24*60;
  printf("%d hr %d min until alarm rings.", x/60, x%60);
  return 0;
}
