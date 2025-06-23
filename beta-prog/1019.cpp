#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();

  int mx = 0;
  string res;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      int k = 0;
      for(;i+k<n and j+k<m and a[i+k]==b[j+k]; ++k);
      if(k > mx) mx=k, res=a.substr(i,k);
    }
  }

  cout << res;

  return 0;
}
