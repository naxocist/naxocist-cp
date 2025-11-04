#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  map<ll, ll> father;
  for(int i=0; i<n; ++i) {
    ll a, b; cin >> a >> b;
    father[b] = a;
  }

  while(q --) {
    ll a, b; cin >> a >> b;

    if(father.find(a) == father.end() or father.find(b) == father.end() or a == b) {
      cout << "NO\n";
      continue ;
    }

    ll fa = father[a], fb = father[b];
    if(father.find(fa) != father.end() && father.find(fb) != father.end() && father[fa] == father[fb]) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  }
  return 0;
}
