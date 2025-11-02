#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e5 + 3;
vector<pii> adj[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x;
  sort(all(v));

  for(auto x : v) cout << x << ' ';
  return 0;
}

