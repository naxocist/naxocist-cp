#include "aplusb.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << sum(a, b);
  return 0;
}
