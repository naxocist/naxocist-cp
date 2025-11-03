#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  set<int> u, i, d;
  string s;

  bool first = 1;
  while(getline(cin, s)) {
    s += ' ';
    int t = 0;
    set<int> r;
    for(int i=0; i<s.size(); ++i) {
      if(s[i] == ' ') r.insert(t), t = 0;
      else t = 10*t + s[i] - '0';
    }

    for(int c : r) u.insert(c);

    if(first) i = r, d = r;
    else {
      set<int> nw;
      for(int c : i) if(r.find(c) != r.end()) nw.insert(c);
      i = nw;

      nw.clear();
      for(int c : d) if(r.find(c) == r.end()) nw.insert(c);
      d = nw;
    }

    first = 0;
  }

  cout << "U: ";
  for(int c : u) cout << c << ' ';
  if(u.empty()) cout << "empty set"; cout << ln;

  cout << "I: ";
  for(int c : i) cout << c << ' ';
  if(i.empty()) cout << "empty set"; cout << ln;

  cout << "D: ";
  for(int c : d) cout << c << ' ';
  if(d.empty()) cout << "empty set"; cout << ln;
  return 0;
}

