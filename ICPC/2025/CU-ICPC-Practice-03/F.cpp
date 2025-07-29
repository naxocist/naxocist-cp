#include <bits/stdc++.h>
using namespace std;

int f(char c, char z) {
  int t = abs(c-z);
  return min(t,26-t);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, p; cin >> n >> p; p--;
  string s; cin >> s;

  int h = n/2;
  if(p >= h) {
    p = n - p - 1;
    reverse(s.begin(), s.end());
  }


  string a = s.substr(0, h);
  string b = s.substr(h+(n%2), h);

  int res = 0;
  for(int i=0; i<h; ++i) {
    res += f(a[i],b[h-1-i]);
  }

  int l=-1, r=-1;
  for(int i=p-1; i>=0; --i) {
    if(a[i]!=b[h-1-i]) l = i;
  }

  for(int i=p+1; i<h; ++i) {
    if(a[i]!=b[h-1-i]) r = i;
  }

  if(l == -1 or r == -1) {
    if(r != -1) res += r-p;
    else if(l != -1) res += p-l;
  }
  else res += r-l + min(p-l,r-p);
  cout << res;
}


