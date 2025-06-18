#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'
#define what(x) cerr << #x << " is " << x << endl;
#define INF 2e9
mt19937 rng;

using T = tuple<int, int, int>;
using ll = long long;
using pi = pair<int, int>;
const int N = 1e5 + 3;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  setIO("shell");
  int n; cin >> n;

  vector<int> shell_at_pos(3), cnt(3); iota(shell_at_pos.begin(), shell_at_pos.end(), 0);
  for(int i=0; i<n; ++i) {
    int a, b, c; cin >> a >> b >> c; a--, b--, c--;
    swap(shell_at_pos[a], shell_at_pos[b]);
    cnt[shell_at_pos[c]] ++;

    for(auto x : shell_at_pos) cout << x << ' ' ; cout << ln;
    for(auto x : cnt) cout << x << ' ' ; cout << ln;
    cout << ln;
  }

  cout << *max_element(cnt.begin(), cnt.end());
  return 0;
}
