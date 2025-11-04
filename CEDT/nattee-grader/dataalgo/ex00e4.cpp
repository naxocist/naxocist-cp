#include <bits/stdc++.h>
using namespace std;

vector<string> res;
int a, b;
string t;

void f(int i, int n) {
  if(b == n) {
    if(i) return ;
    res.emplace_back(t);
    return ;
  }
  t += '0';
  f(i, n + 1);
  t.pop_back();

  if(i == 0) {
    return ;
  }
  t += '1';
  f(i - 1, n + 1);
  t.pop_back();
}

int main() {
  cin >> a >> b;
  f(a, 0);
  for(auto x : res) cout << x << '\n';
  return 0;
}
