#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

bool ar[10];
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; getline(cin, s);


  for(char c : s) {
    if(!isdigit(c)) continue ;
    ar[c-'0'] = 1;
  }

  bool first = true;
  for(int i=0; i<=9; ++i) {
    if(ar[i]) continue ;
    if(!first) cout << ",";
    cout << i;
    first = 0;
  }

  if(first == true) {
    cout << "None";
  }
  return 0;
}

