#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k, n; cin >> k >> n;

  vector<int> clss(1e4 + 1);
  for(int i=0; i<n; ++i) {
    int c, id; cin >> c >> id;
    clss[id] = c;
  }

  queue<int> q, ar[k + 1];

  char op;
  while(cin >> op) {
    if(op == 'X') break ;
    if(op == 'D') {
      if(q.empty()) cout << "empty\n";
      else {
        int kk = q.front();
        cout << ar[kk].front() << '\n'; ar[kk].pop();
        if(ar[kk].empty()) q.pop();
      }
    }

    if(op == 'E') {
      int x; cin >> x;
      int kk = clss[x];
      if(ar[kk].empty()) q.push(kk);
      ar[kk].push(x);
    }
  }
  cout << 0;

  return 0;
}
