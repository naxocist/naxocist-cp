#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string sh, sm; cin >> sh >> sm;
  int h = stoi(sh);
  bool d = 0;
  if(h > 11) h -= 12, d = 1;
  sh = to_string(h);
  if(sh.size() < 2) sh = "0" + sh;

  bool ar[13][15] = {
    {1,1,1, 1,0,1, 1,0,1, 1,0,1, 1,1,1},
    {0,0,1, 0,0,1, 0,0,1, 0,0,1, 0,0,1},
    {1,1,1, 0,0,1, 1,1,1, 1,0,0, 1,1,1},
    {1,1,1, 0,0,1, 1,1,1, 0,0,1, 1,1,1},
    {1,0,1, 1,0,1, 1,1,1, 0,0,1, 0,0,1},
    {1,1,1, 1,0,0, 1,1,1, 0,0,1, 1,1,1},
    {1,1,1, 1,0,0, 1,1,1, 1,0,1, 1,1,1},
    {1,1,1, 0,0,1, 0,0,1, 0,0,1, 0,0,1},
    {1,1,1, 1,0,1, 1,1,1, 1,0,1, 1,1,1},
    {1,1,1, 1,0,1, 1,1,1, 0,0,1, 1,1,1},

    {1,1,1, 1,0,1, 1,1,1, 1,0,1, 1,0,1}, // A 10
    {1,1,1, 1,0,1, 1,1,1, 1,0,0, 1,0,0}, // P 11
    {1,0,1, 1,1,1, 1,0,1, 1,0,1, 1,0,1}, // M 12
  };

  vector<int> v;
  for(char c : sh) v.pb(c-'0'); 
  v.pb(99); // :
  for(char c : sm) v.pb(c-'0'); 
  v.pb(99); // " "
  v.pb(d ? 11 : 10);
  v.pb(12);

  for(int i=0; i<5; ++i) {
    for(int j=0; j<3*8; ++j) {
      int k = j/3, r = i, c = j%3;
      int idx = r*3 + c;
      if(k == 2) cout << (idx == 4 or idx == 10 ? ":" : " ");
      else if(k == 5) cout << " ";
      else cout << (ar[v[k]][idx] ? "#" : " ");

      if((k == 0 or k == 3 or k == 6) and c==2) cout << " ";
    }
    cout << ln;
  }
  return 0;
}