#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
using pi = pair<int, int>;

struct point {
  ll x, y;
};

int orient(point a, point b, point c) {
  point u = {b.x-a.x, b.y-a.y}; // ab
  point v = {c.x-a.x, c.y-a.y}; // ac

  ll area = u.x*v.y - u.y*v.x;
  if(area > 0) return -1;
  if(area < 0) return 1;
  return 0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<point> v;
  for(int i=0; i<n; ++i) {
    int x, y; cin >> x >> y;
    point t={x,y};
    v.pb(t);
  }

  int k; cin >> k;
  while(k--) {
    int x, y; cin >> x >> y;
    point p = {x, y};

    int l = 0, r = n;
    while(l + 1 < r) {
      int m = l + (r-l)/2;
      if(orient(v[0], v[m], p) >= 0) l = m;
      else r = m;
    }

    // cout << x << ' ' << y << ' ' << l << ln;
    if(l == 0 or orient(v[l],v[l+1],p) != 1 or orient(v[l-1],v[l],p)==0) cout << "NO", exit(0);
  }

  cout << "YES";
  return 0;
}