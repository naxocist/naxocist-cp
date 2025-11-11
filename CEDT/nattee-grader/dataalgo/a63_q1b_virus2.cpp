#include <bits/stdc++.h>
using namespace std;

bool f(string s) {
  int len = s.size();
  if(len == 2) return 1;

  int a = 0, b = 0;
  string l, r;
  for(int i=0; i<len; ++i) {
    if(i < len/2) a += s[i] == '1', l += s[i];
    else b += s[i] == '1', r += s[i];
  }

  if(abs(a-b) > 1) return 0; 
  return f(l) and f(r);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q, k; cin >> q >> k;
  while(q--) {
    string s;
    for(int i=0; i<1<<k; ++i) {
      int x; cin >> x; s += '0' + x;
    }

    cout << (f(s) ? "yes" : "no") << '\n';
  }
  return 0;
}
