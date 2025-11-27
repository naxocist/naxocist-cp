#include <bits/stdc++.h>
using namespace std;
vector<string> t;
string s;
int n;

void f(int k) {
  if (k == n) {
    t.emplace_back(s);
    return;
  }

  unordered_set<char> tt;
  for (int i = k; i < n; ++i) {
    if (tt.find(s[i]) != tt.end()) continue;
    tt.insert(s[i]);
    swap(s[k], s[i]);
    f(k + 1);
    swap(s[k], s[i]);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s;
  n = s.size();
  f(0);

  cout << t.size() << '\n';
  sort(t.begin(), t.end());
  for (auto &x : t) cout << x << '\n';
  return 0;
}
