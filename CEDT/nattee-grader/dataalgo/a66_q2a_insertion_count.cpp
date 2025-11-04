#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int fw[N];

int qry(int i) {
  int s = 0;
  for(;i>0;i-=i&-i) s += fw[i]; return s;
}

void upd(int i, int x) {
  for(;i<N;i+=i&-i) fw[i] += x;
}

int main() {
  int n, q; cin >> n >> q;

  map<int, int> mp;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    mp[x] = i - qry(x);
    upd(x, 1);
  }

  while(q --) {
    int k; cin >> k;
    cout << mp[k] << '\n';
  }
  return 0;
}
