
#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)
#define pb emplace_back
#define dump(a) while(a.size())a.pop();
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.f << ',' << x.s << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

const int N = 5e5 + 1, mod = 1e9 + 7, K = 6e5 + 3;
int mn[N][21], mx[N][21];
int qsa[N], qsb[N], qsc[N];
ll fac[K], inv[K];

ll binpow(ll x, ll y) {
  ll res = 1;
  for(;y;x=(x*x)%mod,y>>=1) if(y&1) res = (res*x)%mod;
  return res;
}

ll cnr(int n, int r) {
  if(r>n) return 0;
  return (((fac[n]*inv[n-r])%mod)*inv[r])%mod;
}

void solve() {
  int n, m, s; cin >> n >> m >> s;
  fac[0] = inv[0] = 1;
  for(int i=1; i<K; ++i) {
    fac[i] = fac[i-1]*i, fac[i]%=mod;
    inv[i] = binpow(fac[i], mod-2);
  }

  set<int> z;
  while(s--) {
    int x; cin >> x;
    z.insert(x);
  }

  for(int i=1; i<=n; ++i){
    int t; cin >> t;
    mx[i][0] = mn[i][0] = t;
    int R = t%m, g = __gcd(i+1, n);
    if(g > 1 and z.find(R) != z.end()) qsa[i]++;
    else if(g == 1 and z.find(R) == z.end()) qsb[i]++;
    else qsc[i]++;
  }

  for(int i=1;i<=n;++i) qsa[i]+=qsa[i-1], qsb[i]+=qsb[i-1], qsc[i]+=qsc[i-1];

  for(int i=1; i<21; ++i) {
    for(int j=1; j+(1<<i)-1<=n; ++j) {
      mn[j][i] = min(mn[j][i-1], mn[j+(1<<(i-1))][i-1]);
      mx[j][i] = max(mx[j][i-1], mx[j+(1<<(i-1))][i-1]);
    }
  }

  int q; cin >> q;
  while(q--) {
    int l, r, o; cin >> l >> r >> o;
    int sa = qsa[r]-qsa[l-1], sb = qsb[r]-qsb[l-1], sc = qsc[r]-qsc[l-1]; 

    int lg = log2(r-l+1);
    int qmn = min(mn[l][lg], mn[r-(1<<lg)+1][lg]);
    int qmx = max(mx[l][lg], mx[r-(1<<lg)+1][lg]);

    cout << sa << ' ' << sb << ' ' << sc << ' ' << qmx - qmn << ' ';
    if(o) cout << cnr(n+m,max({sa, sb, sc}));
    cout << '\n';
  }
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
