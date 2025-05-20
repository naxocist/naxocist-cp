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
  unordered_map<int, int> same, cnt, notsame;

  for(int i=l; i<=r; ++i)  {
    for(int j=l; j<=r; ++j) {
      if(i == j) same[i+j] ++;
      else notsame[i+j] ++;
    }
    cnt[i] ++;
  }

  ll x = 0, y = 0;
  for(int k=l; k<=r; ++k) {
    for(int p : prime) {
      x += notsame[p-k] - 2*cnt[p-2*k];
      y += same[p-k] + 2*cnt[p-2*k];
    }
  }

  cout << y/3 + x/6;

  return 0;
}
