#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> res;
ll n, k;

void f(ll i) {
  if(i >= n) return ;
  res.emplace_back(i);

  f(2*i+1);
  f(2*i+2);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  f(k);

  cout << (int)res.size() << '\n';
  sort(res.begin(), res.end());
  for(auto &r : res) cout << r << ' ';
  return 0;
}
