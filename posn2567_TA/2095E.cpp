#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,k;
int binpow(int a, int b) {
  int res=1;
  for(;b>0;b>>=1){
  	if(b&1)res*=a;
  	a*=a,res%=p,a%=p;
  }
  return res;
}

signed main() {
  cin >> n >> p >> k;

  map<int,int> mp;
  
  int res=0,mn=INT_MAX;
  for(int i=0;i<n;++i){
  	int x; cin >> x; mn=min(mn,x);
  	if(!x) continue;
  	int t=binpow(x,3);
  	int inv=binpow(t,p-2);
  	res+=mp[t];
  	mp[(k*inv)%p]++;
  }

  if(k==0)cout<<(mn==0?n-1:0);
  else cout << res;
  return 0;
}
