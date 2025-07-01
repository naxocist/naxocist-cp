#include <bits/stdc++.h>
using namespace std;

#define ln '\n';

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; ++i) {
    int k = i; while(k--) cout << "#"; cout << '\n';
  }
  return 0;
}