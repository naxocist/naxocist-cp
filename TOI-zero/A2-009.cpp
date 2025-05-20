#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int ar[33][33];
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, c; cin >> n >> c; 

  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin >> ar[i][j];


  queue<int> q; for(int i=1; i<=n; ++i) q.push(i);

	while(q.size() > 1) {
		int u = q.front(); q.pop();
		int v = q.front(); q.pop();

		int w = ar[u][v];
		if(w == u and c == v) c = 0, w = v;
		if(w == v and c == u) c = 0, w = u;
		q.push(w);
	}

	cout << q.front();
  return 0;
}
