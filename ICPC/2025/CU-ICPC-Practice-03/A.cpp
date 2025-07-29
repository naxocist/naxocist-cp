#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  if(n&1) {
    int k = n/2 - 1;
    cout << k+1 << '\n';
    while(k--) cout << 2 << ' ';
    cout << 3;
  }else {
    int k = n/2;
    cout << k << '\n';
    while(k--) cout << 2 << ' ';
  }
  return 0;
}
