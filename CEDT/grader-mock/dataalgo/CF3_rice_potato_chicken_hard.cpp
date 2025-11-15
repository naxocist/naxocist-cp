#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
deque<pll> dq;
multiset<pll> ms;
bool gone[2000003];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  int t = 0;
  while(n --) {
    int x; cin >> x;
    dq.emplace_back(x, t);
    ms.emplace(x, t++);
  }

  ll s = 0;
  while(q --) {
    ll o, x; cin >> o;
    if(o == 1) {
      // add x to the right
      cin >> x;
      dq.emplace_back(x - s, t);
      ms.emplace(x - s, t++); 
    }
    if(o == 2) {
      // del left-most
      while(gone[dq.front().second]) dq.pop_front();
      ms.erase(ms.find(dq.front()));
      dq.pop_front();
    }
    if(o == 3) {
      // del right-most
      while(gone[dq.back().second]) dq.pop_back();
      ms.erase(ms.find(dq.back()));
      dq.pop_back();
    }
    if(o == 4) {
      // +x to all
      cin >> x;
      s += x;
    }
    if(o == 5) {
      // remove all < x
      cin >> x;
      for(auto it=ms.begin(); it!=ms.end() and it->first + s < x;) {
        gone[it->second] = true;
        it = ms.erase(it);
      }
    }
    if(o == 6) {
      // remove x number from right
      cin >> x;
      ll f = 0;
      while(x --) {
        while(gone[dq.back().second]) dq.pop_back();
        ms.erase(ms.find(dq.back()));
        f += dq.back().first + s;
        dq.pop_back();
      }

      dq.emplace_front(f-s, t);
      ms.emplace(f-s, t++); 
    }
  }

  ll sum = 0;
  for(auto &[a, b] : ms) sum += a + s;
  cout << (int)ms.size() << ' ' << sum;
  return 0;
}
