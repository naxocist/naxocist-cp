#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;

  auto f = [&](int x) {
    for(int i=2; i<=1e4; ++i){
      for(ll j=i*i,c=2;j<=x;j*=i,c++){
        if(j==x)return c;
      }
    }
    return -1*1ll;
  };

  while(q--){
    int x; cin >> x;
    int r=f(x);
    if(r==-1)cout<<"NO\n";
    else cout<<r<<'\n';
  }
  return 0;
}
