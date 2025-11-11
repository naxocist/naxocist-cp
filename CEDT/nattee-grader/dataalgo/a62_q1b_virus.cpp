#include <bits/stdc++.h>
using namespace std;

bool f(string s) {
  int len = s.size();
  if(len == 2) return s == "01";

  int h = len/2;
  string l = s.substr(0, h), r = s.substr(h, h);
  string rl = l;
  reverse(rl.begin(), rl.end());

  return (f(l) or f(rl)) and f(r);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q, k; cin >> q >> k;

  while(q --) {
    string s;
    for(int i=0; i<1<<k; ++i) {
      int x; cin >> x; s += x + '0';
    }
    cout << (f(s) ? "yes" : "no") << '\n';
  }
  return 0;
}
