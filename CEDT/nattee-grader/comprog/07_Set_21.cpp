#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int k; cin >> k;
  
  unordered_set<int> us;

  ll res = 0;
  int x;
  for(;cin>>x;) {
    if(us.find(k-x) != us.end()) res ++;
    us.insert(x);
  }

  cout << res; 
  return 0;
}

