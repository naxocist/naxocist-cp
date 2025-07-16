#include <bits/stdc++.h>
using namespace std;

int n, d, x;

int getNextX() {
  x = (x * 37LL + 10007) % 1000000007;
  return x;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> d >> x;

  vector<int> a(n), b(n);

  for(int i = 0; i < n; i = i + 1){
    a[i] = i + 1;
  }
  for(int i = 0; i < n; i = i + 1){
    swap(a[i], a[getNextX() % (i + 1)]);
  }

  for(int i = 0; i < n; i = i + 1){
    if (i < d) b[i] = 1;
    else b[i] = 0;
  }
  for(int i = 0; i < n; i = i + 1){
    swap(b[i], b[getNextX() % (i + 1)]);
  }

  vector<int> idx(n + 1);
  vector<int> one;
  for(int i=0; i<n; ++i) if(b[i]) one.emplace_back(i);
  for(int i=0; i<n; ++i) idx[a[i]] = i;

  int y = 50;
  for(int i=0; i<n; ++i) {
    int j;
    for(j=n; j>=n-y; --j) {
      if(j > 0 and i >= idx[j] and b[i-idx[j]]) {
        cout << j << '\n'; break ;
      }
    }

    if(j < n-y) {
      int mx = 0;
      for(auto o : one) {
        if(o > i) break ;
        mx = max(mx, a[i-o]);
      }
      // for(int j=0; j<=i; ++j) mx = max(mx, a[j]*b[i-j]);
      cout << mx << '\n';
    }
  }

  return 0;
}
