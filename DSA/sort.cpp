#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

void combine(int l, int m, int r, vector<int> &v, vector<int> &t) {
  int a = l, b = m+1;
  for(int i=l; i<=r; ++i) {
    if(a > m) {
      t[i] = v[b ++];
      continue ;
    }
    if(b > r) {
      t[i] = v[a ++];
      continue ;
    }
    t[i] = v[a] < v[b] ? v[a ++] : v[b ++];
  }

  for(int i=l; i<=r; ++i) v[i] = t[i];
}

void merge_sort(int l, int r, vector<int> &v, vector<int> &t) {
  if(l == r) return ;
  int m = l + (r-l)/2;
  merge_sort(l, m, v, t);
  merge_sort(m+1, r, v, t);
  combine(l, m, r, v, t);
}

void quick_sort(int l, int r, vector<int> &v) {
  if(l == r) return ;

  int pivot = v[l];
  int a = l - 1, b = r + 1;
  while(1) {
    do {
      a ++;
    } while(v[a] < pivot);

    do {
      b --;
    } while(v[b] > pivot);

    if(a >= b) break ;
    swap(v[a], v[b]);
  }

  quick_sort(l, b, v);
  quick_sort(b+1, r, v);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x;
  vector<int> t(v.size());
  // merge_sort(0, n-1, v, t);
  quick_sort(0, n-1, v);

  for(auto &x : v) cout << x << ' ';
  return 0;
}

