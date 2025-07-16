#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int mod = 998244353;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  priority_queue<int> pq;
  vector<int> v(n); for(auto &x : v) cin >> x, pq.emplace(x);

  vector<bool> t(n+1);
  ll s = 0;
  for(int i=0; i<k; ++i) {
    int x = pq.top(); pq.pop();
    s += x;
    t[x]=1;
  }

  vector<int> pos;
  for(int i=0; i<n; ++i) {
    if(t[v[i]]) pos.pb(i);
  }

  ll cnt = 1;
  for(int i=0; i<pos.size()-1; ++i) {
    cnt *= pos[i+1] - pos[i];
    cnt %= mod;
  }


  cout << s << ' ' << cnt;
  return 0;
}
