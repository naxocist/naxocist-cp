#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  string ar[n]; for(int i=0; i<n; ++i) cin >> ar[i];
  cin.ignore();
  string s; getline(cin, s);

  string tmp[n];
  for(char c : s) {
    if(c == 'C') {
      for(int i=0; i<n; ++i) tmp[i] = ar[i];
      for(int i=0; i<n/2; ++i) ar[i] = ar[n/2+i];
      for(int i=n/2; i<n; ++i) ar[i] = tmp[i-n/2];
    }else if(c == 'S'){
      for(int i=0; i<n; ++i) tmp[i] = ar[i];
      for(int i=0; i<n; i++) ar[i] = i&1 ? tmp[n/2+i/2] : tmp[i/2];
    }
  }

  for(int i=0; i<n; ++i) cout << ar[i] << ' ';
  return 0;
}

