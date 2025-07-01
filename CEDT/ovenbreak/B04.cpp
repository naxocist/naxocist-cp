#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  vector<string> v, sym;
  for(int i=0; i<4; ++i) {
    string s; cin >> s;
    v.pb(s);
  }
  sym = v;
  sort(all(v));

  vector<string> nw;
  for(int i=x-1, j=4; j>0; j--, i=(i+1)%4) nw.pb(v[i]);

  vector<int> ord(4);
  for(int k=0; k<4; ++k) for(int i=0; i<4; ++i) if(nw[i] == sym[k]) ord[k] = i + 1;

  bool w = ((x == 1) or ord[1] == 1) and ord[3] > ord[2];
  bool u = ord[2] > ord[1] and ord[2] < ord[0] and ord[3] != 3;
  bool tt = (w^u and ord[0] > ord[3]) or ord[1] != 4;

  bool open = tt and (ord[3] < ord[1] or ord[2] > ord[0]);

  if(!open) cout << "No Croissant :(", exit(0);
  
  cout << "CROISSANT with ordering: ";
  for(int i=0; i<4; ++i) cout << ord[i] << ' ';
  return 0;
}