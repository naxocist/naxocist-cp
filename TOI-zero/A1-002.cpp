#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int a, b, c, d;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  while(x) {
  	if(x >= 10) x -= 10, a++;
  	else if(x >= 5) x -= 5, b++;
  	else if(x >= 2) x -= 2, c++;
  	else x--, d++;
  }

  printf("10 = %d\n5 = %d\n2 = %d\n1 = %d", a, b, c, d);
  return 0;
}
