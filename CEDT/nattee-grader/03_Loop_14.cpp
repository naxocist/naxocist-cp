#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b; 
  getline(cin, a);
  getline(cin, b);


  if(a.size() != b.size()) {
    cout << "Incomplete answer";
    return 0;
  }

  int res = 0;
  for(int i=0; i<a.size(); ++i) {
    res += a[i] == b[i];
  }

  cout << res;

  return 0;
}

