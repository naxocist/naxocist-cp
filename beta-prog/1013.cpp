#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'

string pre;
unordered_map<char, int> um = {{'+', 0}, {'*', 1}, {'^', 2}, {'(', 3}};
vector<int> v;

string f(int l, int r, string s, int i) {
  int len = r-l+1;

  if(i == v.size()) return s.substr(l, len);
  if(len <= 0) return "";

  vector<int> pos[4];

  for(int i=0; i<4; ++i) pos[i].pb(l-1);
  
  int mn = 1e9, p = -1, br = 0;
  for(int j=l; j<=r; ++j) {
    char c = s[j];
    if(um.find(c) != um.end() and !br) {
      int k = um[c];
      if(k < mn) mn = k, p = j;
      pos[k].pb(j);
    }
    if(c == '(') br ++;
    if(c == ')') br --;
  }
  for(int i=0; i<4; ++i) pos[i].pb(r+1);

  int want = v[i];

  if(mn == 3) return want > 1 ? "null" : f(l+1,r-1,s,i+1);
  if(mn == 1e9) mn = 2;

  return want > pos[mn].size() - 1 ? "null" : f(pos[mn][want-1]+1,pos[mn][want]-1,s,i+1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size();

  int q; cin >> q;
  while(q--) {

    pre = "";
    v.clear();
    while(1) {
      int x; cin >> x;
      if(x == 0) break ;
      v.pb(x);
    }

    for(auto it=v.rbegin(); it!=v.rend(); ++it) pre += "op(" + to_string(*it) + ",";
    pre += "p"; int k = v.size(); while(k--) pre += ")"; pre += "=";
    cout << pre << f(0, n-1, s, 0) << ln;
  }

  return 0;
}
