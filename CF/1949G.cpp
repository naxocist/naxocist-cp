#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
vector<string> res;

void drive(int x) { res.pb("DRIVE " + to_string(x+1)); }

void pick() { res.pb("PICKUP"); }

void drop() { res.pb("DROPOFF"); }

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  string a, b; cin >> a >> b;

  bool dif = 0;
  for(int i=0; i<n; ++i) {
    if(a[i] != '-' and a[i] != b[i]) {
      dif = 1;
    }
  }
  if(!dif) cout << 0, exit(0);


  int m = 0, c = 0;
  for(int i=0; i<n; ++i) {
    m += (a[i] == 'M') - (b[i] == 'M');
    c += (a[i] == 'C') - (b[i] == 'C');
  }

  m = max(0, -m), c = max(0, -c);

  for(int i=0; i<n; ++i) {
    if(a[i] == '-') continue ;
    if(m > 0 and b[i] == 'M') m--, b[i] = '-';
  }

  for(int i=0; i<n; ++i) {
    if(a[i] != '-') continue ;
    if(m > 0 and b[i] == 'M') m--, b[i] = '-';
  }

  for(int i=0; i<n; ++i) {
    if(a[i] == '-') continue ;
    if(c > 0 and b[i] == 'C') c--, b[i] = '-';
  }

  for(int i=0; i<n; ++i) {
    if(a[i] != '-') continue ;
    if(c > 0 and b[i] == 'C') c--, b[i] = '-';
  }

  vector<bool> vis(n);
  while(1) {
    int crr = -1;
    for(int i=0; i<n and crr == -1; ++i) {
      if(a[i] == '-' and b[i] != '-' and !vis[i]) crr = i;
    }

    if(crr == -1) break ;

    vis[crr] = 1;
    drive(crr);
    pick();

    while(1) {

      int need = -1;
      for(int i=0; i<n and need == -1; ++i) {
        if(a[i] == b[crr] and b[i] != '-' and !vis[i]) need = i;
      }

      for(int i=0; i<n and need == -1; ++i) {
        if(a[i] == b[crr] and b[i] == '-' and !vis[i]) need = i;
      }

      vis[need] = 1;
      drive(need);
      drop();

      if(b[need] == '-') break ;
      pick();
      crr = need;
    }
  }

  cout << res.size() << ln;
  for(auto r : res) cout << r << ln;
  return 0;
}
