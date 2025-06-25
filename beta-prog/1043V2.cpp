#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
bool no[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> prime;
  for(int i=2; i<N; ++i) {
    if(no[i]) continue ;
    prime.emplace_back(i);
    for(int j=i*i; j<N; j+=i) no[j] = 1;
  }

  int q; cin >> q;
  while(q--) {
    int x; cin >> x;
    int gcd = -1;
    for(int p : prime) {
      if(x % p) continue ;
      int cnt = 0;
      while(x % p == 0) {
        x /= p;
        cnt ++;
      }
      if(gcd == -1) gcd = cnt;
      else gcd = __gcd(gcd, cnt);
    }

    if(x != 1 or gcd == 1) cout << "NO\n";
    else cout << gcd << '\n';
  }
  return 0;
}
