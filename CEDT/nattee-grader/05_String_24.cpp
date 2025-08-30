#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back
string ar[1000000];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  
  string s;
  int sz = 0;
  while(cin >> s) {
    ar[sz ++] = s;
  }



  string aeiou = "aeiou";
  int i = 0, j = 0;
  while(aeiou.find(ar[0][i]) == string::npos) i ++;
  while(aeiou.find(ar[sz-1][j]) == string::npos) j ++;

  string t = ar[0];
  ar[0] = ar[0].substr(0, i) + ar[sz-1].substr(j);
  ar[sz-1] = ar[sz-1].substr(0, j) + t.substr(i);

  for(int i=0; i<sz; ++i) cout << ar[i] << ' ';
  return 0;
}

