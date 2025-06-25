#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 1;
int ar[N];

void solve() {
  int n; cin >> n;
  ar[0] = -1e9;

  bool ok = 0;
  for(int i=1; i<=n; ++i) {
    cin >> ar[i];
    if(abs(ar[i] - ar[i-1]) <= 1) {
      ok = 1;
    }
  }

  if(ok) {
    cout << 0 << ln; return ;
  }

  for(int i=1; i<n; ++i) {
    int l = min(ar[i], ar[i+1]), r = max(ar[i], ar[i+1]);
    if(l-1 <= ar[i-1] and ar[i-1] <= r+1) {
      cout << 1 << ln; return ;
    }
    if(i + 2 <= n and l-1 <= ar[i+2] and ar[i+2] <= r+1) {
      cout << 1 << ln; return ;
    }
  }

  cout << -1 << ln; return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}


