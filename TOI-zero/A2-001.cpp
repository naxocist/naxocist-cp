#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) x.begin(), x.end()
#define pb emplace_back

const int N = 3e2 + 1;
int red[N],blue[N];


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<int> a(n+1), b(m+1);
  int res = 0;
  for(int i=1; i<=n; ++i) cin >> a[i];
  for(int i=1; i<=m; ++i) cin >> b[i];

  set<int> s;
  for(int i=0; i<n; i++) {
  	for(int j=0; j<m; j++) {
  		if(i%2 == j%2) {
  			if(a[i] == b[j] || a[i+1] == b[j+1]) {
  				s.insert(a[i] == b[j] ? a[i] : a[i+1]);
  				continue ;
  			}	
  		}else {
  			if(a[i] == b[j+1] || a[i+1] == b[j]) {
  				s.insert(a[i] == b[j+1] ? a[i] : a[i+1]);
  				continue ;
  			}
  		}

  		if(i%2 == j%2) {
  			res += (b[j]<a[i]&&b[j+1]>a[i+1])||(b[j]>a[i]&&b[j+1]<a[i+1]);
  		}else {
  			res += (b[j]<a[i+1]&&b[j+1]>a[i]);
  		}
  	}
  }
  
  cout << res + s.size();
  return 0;
}
