#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;

#define pb emplace_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; cin >> n;
  vector<int> v(n);

  for(int i=1; i<=n; ++i) {
    int x; cin >> x;
    v[i] = v[i-1] + x;
  }

  int n; cin >> n; cout << n * n << '\n';
  int x; cin >> x; cout << x * x << '\n';

  cout << v[n] << '\n';

  return 0;
}
