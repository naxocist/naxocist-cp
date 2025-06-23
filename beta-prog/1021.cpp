#include <bits/stdc++.h>
using namespace std;

#define ln '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  
  priority_queue<int> pq;
  while(q--) {
    char o; int x; cin >> o;
    if(o == 'P') {
      cin >> x;
      pq.emplace(x);
    }else {
      if(pq.empty()) {
        cout << -1 << ln; continue ;
      }
      cout << pq.top() << ln; pq.pop();
    }
  }
  return 0;
}
