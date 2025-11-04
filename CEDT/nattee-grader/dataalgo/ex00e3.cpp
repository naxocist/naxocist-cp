#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> cnt(n + 1);
  bool ok = 1;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    if(x < 1 or x > n or ++cnt[x] > 1) ok = 0;
  }

  if(ok) {
    cout << "YES";
  }else {
    cout << "NO";
  }
  return 0;
}
