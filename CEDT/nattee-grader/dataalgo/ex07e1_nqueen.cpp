#include <bits/stdc++.h>
using namespace std;

int n;
int res = 0;
const int N = 15;
bool rr[2*N], cc[2*N], d1[2*N], d2[2*N];

void f(int r) {
  if(r == n) {
    res ++;
    return ;
  }
  for(int c=0; c<n; ++c) {
    if(rr[r] or cc[c] or d1[n-c-1+r] or d2[c+r]) continue ;
    rr[r] = cc[c] = d1[n-c-1+r] = d2[c+r] = true; 
    f(r+1);
    rr[r] = cc[c] = d1[n-c-1+r] = d2[c+r] = false; 
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  f(0);
  cout << res;
  return 0;
}
