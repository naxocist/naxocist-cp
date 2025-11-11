#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int f(int i, int s, int l) {
  if(s <= 0 or i <= 0) return s == 0;
  return f(i-1,s,l+1) + f(i-1,s-l,l);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  cout << f(n,n,1);
  return 0;
}
