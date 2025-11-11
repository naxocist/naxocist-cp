#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
vector<int> need;
vector<int> r;
vector<bool> used;
int n, k;

void f() {
  if ((int)r.size() == n) {
    for (auto &x : r)
      cout << x << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; ++i) {
    if(used[i] or (need[i] != -1 and !used[need[i]])) continue ;
    used[i] = 1;
    r.pb(i);
    f();
    used[i] = 0;
    r.pop_back();
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  used.resize(n);
  need.resize(n, -1);
  while (k--) {
    int a, b;
    cin >> a >> b;
    need[b] = a;
  }
  f();

  return 0;
}
