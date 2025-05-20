#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;

  vector<int> f = {4, 1, 3, 6, 5, 2}; 
  vector<int> b = {2, 6, 3, 1, 5, 4}; 
  vector<int> l = {5, 2, 1, 4, 6, 3}; 
  vector<int> r = {3, 2, 6, 4, 1, 5}; 
  vector<int> c = {1, 5, 2, 3, 4, 6}; 
  vector<int> d = {1, 3, 4, 5, 2, 6}; 

  while(q--) {
    vector<int> v = {1, 2, 3, 5, 4, 6};
    string s; cin >> s;
    for(char t : s) {
      vector<int> nxt(6);
      for(int i=0; i<6; ++i) {
        if(t == 'F') nxt[i] = v[f[i] - 1];
        if(t == 'B') nxt[i] = v[b[i] - 1];
        if(t == 'L') nxt[i] = v[l[i] - 1];
        if(t == 'R') nxt[i] = v[r[i] - 1];
        if(t == 'C') nxt[i] = v[c[i] - 1];
        if(t == 'D') nxt[i] = v[d[i] - 1];
      }

      v = nxt;
    }
    cout << v[1] << ' ';
  }

  return 0;
}

