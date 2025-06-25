#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;
int x[N],y[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m,k; cin >> n >> m >> k;
  while(k--){
    int a,b,r; cin >> a >> b >> r;
    for(int i=max(0,a-r);i<=min(5000,a+r);++i) x[i]++;
    for(int i=max(0,b-r);i<=min(5000,b+r);++i) y[i]++;
  }
  int mx=0;
  for(int i=0;i<=n;++i) mx=max(mx,x[i]);
  for(int i=0;i<=m;++i) mx=max(mx,y[i]);
  cout << mx;
  return 0;
}
