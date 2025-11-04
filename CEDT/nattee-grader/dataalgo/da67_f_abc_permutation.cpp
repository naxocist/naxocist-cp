#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<string> res;
string s;

void f(int i, int la, int lb, int lc) {
  if(i == n) {
    res.emplace_back(s);
    return ;
  }

  if(la > 0) {
    s += 'A';
    f(i+1,la-1,lb,lc);
    s.pop_back();
  }
  if(lb > 0) {
    s += 'B';
    f(i+1,la,lb-1,lc);
    s.pop_back();
  }
  if(lc > 0) {
    s += 'C';
    f(i+1,la,lb,lc-1);
    s.pop_back();
  }
}

int main() {
  cin >> n >> a >> b >> c;

  f(0, a, b, c);
  cout << (int)res.size() << '\n';
  for(auto r : res) {
    cout << r << '\n';
  }
  return 0;
}
