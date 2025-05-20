// C2T14 - Digging Daimond
#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
using T = tuple<int, int, int>;
const int N = 50;
bool vis[N][N][N], ar[N][N][N];
int x, y, z;

bool ok(int i, int j, int k) {
  return i>=0 and i<x and j>=0 and j<y and k>=0 and k<z;
}

void count_component() {

  int cnt = 0;
  memset(vis, 0, sizeof vis);
  for(int i=0; i<x; ++i) for(int j=0; j<y; ++j) for(int k=0; k<z; ++k) {

  	if(vis[i][j][k] or ar[i][j][k] == 0) continue ;

  	cnt ++;
  	queue<T> q; q.emplace(i, j, k); vis[i][j][k] = 1;
  	while(q.size()) {
  		auto [a, b, c] = q.front(); q.pop();

  		for(int di=-1; di<=1; ++di) {
  			for(int dj=-1; dj<=1; ++dj) {
  				for(int dk=-1; dk<=1; ++dk) {
  					if(abs(di) + abs(dj) + abs(dk) >= 2) continue ; // continue if there are >= 2 axis changes

  					int ii = a + di, jj = b + dj, kk = c + dk;
  					if(!ok(ii, jj, kk) or !ar[ii][jj][kk] or vis[ii][jj][kk]) continue ;
  					vis[ii][jj][kk] = 1;
  					q.emplace(ii, jj, kk);
  				}
  			}
  		}
  	}

  }

  cout << cnt << '\n';
  return ;
}
int main(){
  cin >> x >> y >> z;
  for(int i=0; i<x; ++i) {
  	for(int j=0; j<y; ++j) {
  		for(int k=0; k<z; ++k) 
  			cin >> ar[i][j][k];
  	}
  }

  count_component();
  int q; cin >> q;
  while(q--) {
  	int a, b, c, r; cin >> a >> b >> c >> r; // input bomb coordinate and radius
  	for(int i=a-r; i<=a+r; ++i) {
  		for(int j=b-r; j<=b+r; ++j) {
  			for(int k=c-r; k<=c+r; ++k) if(ok(i,j,k)) ar[i][j][k] = 0;
  		}
  	}
  }
  count_component();
}
