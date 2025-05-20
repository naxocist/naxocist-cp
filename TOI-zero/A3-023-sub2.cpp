#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 15001;
bool isprime[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  memset(isprime, 1, sizeof isprime);
  isprime[0] = isprime[1] = 0;

  vector<int> prime;
  for(int i=2; i<N; ++i) {
    if(!isprime[i]) continue ;
    prime.pb(i);
    for(int j=i*i; j<N; j+=i) {
      isprime[j] = 0;
    }
  }

  int l, r; cin >> l >> r;

  ll x = 0, y = 0;
  for(int i=l; i<=r; ++i) for(int j=l; j<=r; ++j) for(int k=l; k<=r; ++k) {
    if(!isprime[i+j+k]) continue ;
    int d = (i == j) + (j == k) + (i == k);
    // d < 1 
    if(d) y++;
    else x++;
  }

  cout << x << ln;

  cout << y/3 + x/6;
  return 0;
}
