#include <bits/stdc++.h>
using namespace std;

int g;
const int N = 103;
int dsu[N];

int par(int u) {
  return u == dsu[u] ? u : dsu[u] = par(dsu[u]);
}

void un(int u, int v) {
  u=par(u), v=par(v);
  if(u == v) return ;
  dsu[u] = v;
  g--;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  iota(dsu, dsu+n, 0);
  vector<int> x(n), y(n);
  for(int i=0; i<n; ++i) {
    cin >> x[i] >> y[i];
  }

  g = n;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if(x[i] == x[j] or y[i] == y[j]) un(i,j);
    }
  }

  cout << g-1;
  
}


