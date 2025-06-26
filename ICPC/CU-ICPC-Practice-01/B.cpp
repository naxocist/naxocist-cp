#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 1;
bool no[N];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  set<ll> s;
  for(ll i=2; i<N; ++i) {
    if(no[i]) continue; 
    s.insert(i*i);
    for(ll j=i*i; j<N; j+=i) no[j] = 1;
  }

  int n; cin >> n;
  while(n--) {
    ll x; cin >> x;
    if(s.find(x) != s.end()) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
