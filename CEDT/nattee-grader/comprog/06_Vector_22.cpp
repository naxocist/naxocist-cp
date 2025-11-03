#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

vector<int> cntv, pv, stv, iv;

bool cmp(int i, int j) {
  if(cntv[i] != cntv[j]) return cntv[i] < cntv[j];
  if(pv[i] != pv[j]) return pv[i] < pv[j];
  if(stv[i] != stv[j]) return stv[i] < stv[j];

  return iv[i] < iv[j];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x;

  int cnt = 0, p = -1, st = 0, i = 0;

  using T= tuple<int, int, int, int>;
  vector<T> res;
  int mx = 0;
  while(cin >> x) {
    if(x != p and p != -1) {
      cntv.pb(cnt); pv.pb(p); stv.pb(st); iv.pb(i);
      mx = max(mx, cnt);
      st = i;
      cnt = 0;
    }

    cnt ++;
    i ++;
    p = x;
  }
  mx = max(mx, cnt);
  cntv.pb(cnt); pv.pb(p); stv.pb(st); iv.pb(i);

  vector<int> idx;
  for(int i=0; i<cntv.size(); ++i) idx.pb(i);
  sort(all(idx), cmp);

  for(int i=0; i<cntv.size(); ++i) {
    int j = idx[i];
    if(cntv[j] != mx) continue ;
    printf("%d --> x[ %d : %d ]\n", pv[j], stv[j], iv[j]);
  }
  return 0;
}

