#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
#define loop(x,n) for(int x = 0; x < n; ++x)

const int N = 12;
int ar[N][N], t[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  loop(i, 9) loop(j, 9) cin >> ar[i][j];

  for(int k=1; k<=n; ++k) {
    bool ok = 1;
    loop(i, 9) loop(j, 9) {
      cin >> t[i][j];
      // cout << t[i][j] << " \n"[j == 8];
      if(ar[i][j] != 0 and t[i][j] != ar[i][j]) ok = 0;
    }

    loop(i, 9) {
      vector<int> cnt(9 + 1);
      loop(j, 9) if(++cnt[t[i][j]] > 1) ok = 0;
      fill(all(cnt), 0);
      loop(j, 9) if(++cnt[t[j][i]] > 1) ok = 0;
    }

    loop(i, 3) {
      loop(j, 3) {
        vector<int> cnt(9 + 1);
        loop(a, 3) {
          loop(b, 3) {
            int r = 3*i + a, c = 3*j + b;
            if(++cnt[t[r][c]] > 1) ok = 0;
          }
        }
      }
    }

    if(ok) cout << k << ln;
  }

  cout << "END";

  return 0;
}
