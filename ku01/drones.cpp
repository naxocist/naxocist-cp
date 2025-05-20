#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int n, x;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  priority_queue<int> a, b;
  for(int i=1; i<=200; ++i) {
  	a.emplace(-i); int k = 9; while(k--) a.emplace(-2*i);
  }

  while(n--) cin >> x, b.emplace(x);

  ll res = 0;
  while(b.size()) res += -a.top()*b.top(), a.pop(), b.pop();
  
  cout << res;
  return 0;
}
