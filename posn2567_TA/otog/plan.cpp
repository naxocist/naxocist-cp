#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 3;
char ar[N][N][N];
bool vis[N][N];

using pi = pair<int, int>;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int k, n, m; cin >> k >> n >> m;

	vector<int> mxx;
	for(int i=1; i<=k; ++i) {
		for(int j=1; j<=n; ++j) {
			string s; cin >> s;
			for(int h=1; h<=m; ++h) {
				ar[i][j][h] = s[h-1];
			}
		}

		memset(vis, 0, sizeof vis);
		queue<pi> q;

		int r = 0;
		for(int j=1; j<=n; ++j) {
			for(int h=1; h<=m; ++h) {
				if(vis[j][h] or ar[i][j][h] == '#') continue;
				int cnt = 0;
				q.emplace(j, h);
				while(q.size()) {
					int ii, jj; tie(ii, jj) = q.front(); q.pop();
					if(vis[ii][jj]) continue; 
					// cout << ii << ' ' << jj << endl;
					vis[ii][jj] = 1;
					cnt += ar[i][ii][jj] == 'X';
					int t[] = {1, 0, -1, 0, 1};
					for(int g=0; g<4; ++g) {
						int ni = ii+t[g], nj = jj+t[g+1];
						if(ni < 1 or ni > n or nj < 1 or nj > m or vis[ni][nj] or ar[i][ni][nj] == '#') continue ;
						q.emplace(ni, nj);
					}
				}
				// cout << "T: " << cnt << endl;

				r = max(r, cnt);
			}
		}
			// cout << "---\n";
// 
		mxx.emplace_back(r);
	}


	sort(mxx.rbegin(), mxx.rend());
	// for(auto x : mxx) cout << x << ' '; cout << endl;
	int q; cin >> q;
	while(q--) {
		int x; cin >> x;
		int l = -1, r = k + 1;
		while(l + 1 < r) {
			int m = l + (r-l)/2;
			int t = x;
			bool ok = false;
			for(int i=0; i<m; ++i) {
				t -= mxx[i];
				if(t <= 0) ok = true;
			}
			if(ok) r = m;
			else l = m;
		}

		if(r == k + 1) r = -1;
		cout << r << '\n';
	}

	return 0;
}