#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

vector<int> can[20];
int tum[1000];
int n, k;
int res = INT_MAX;

void f(int i, int done, int cnt) {
  if(done == n) {
    res = min(res, cnt);
    return ;
  }
  if(i == k) return ;
  if(cnt >= res) return ;

  for(int &x : can[i]) {
    if(tum[x] == 0) done ++;
    tum[x] ++;
  }
  f(i + 1, done, cnt + 1);
  for(int &x : can[i]) {
    tum[x] --;
    if(tum[x] == 0) done --;
  }
  f(i + 1, done, cnt);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> k;
  for(int i=0; i<k; ++i) {
    int m; cin >> m;
    while(m --) {
      int x; cin >> x; x--;
      can[i].pb(x);
    }
  }

  f(0, 0, 0);
  cout << res;
  return 0;
}


