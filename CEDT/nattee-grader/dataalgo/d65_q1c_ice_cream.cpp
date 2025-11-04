#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, st; cin >> n >> m >> st;

  vector<int> v(1e5 + 1);
  v[0] = st;
  while(n --) {
    int a, s; cin >> a >> s;
    v[a] = s;
  }

  for(int i=0; i<=1e5; ++i) if(!v[i]) v[i] = v[i-1];
  for(int i=1; i<=1e5; ++i) v[i] += v[i-1];

  while(m --) {
    int p, x; cin >> p >> x;
    auto t = lower_bound(begin(v), begin(v)+x+1, p);
    if(t == begin(v)+x+1) {
      t = lower_bound(begin(v)+x+1, end(v), p+v[x]);
    }

    cout << t - begin(v) << ' ';
  }
  return 0;
}
