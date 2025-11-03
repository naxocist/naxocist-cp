#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; double v;

  vector<string> name;
  vector<double> val;
  while(cin >> s) {
    if(s == "END") break ;
    cin >> v;
    name.pb(s); val.pb(v);
  }


  double n = name.size();
  vector<double> sum(name.size());
  while(cin >> s) {
    double idx = find(all(name), s) - begin(name);
    if(idx == n) continue ;
    sum[idx] += val[idx];
  }

  vector<double> t = sum;
  sort(t.rbegin(), t.rend());

  int k = 3;
  for(auto m : t) {
    if(!m or k == 0) break ;
    k --;
    for(double i=0; i<n; ++i) {
      if(sum[i] == INT_MIN or sum[i] != m) continue ;
      cout << name[i] << ' ' << sum[i] << ln;
      sum[i] = INT_MIN;
    }
  }

  if(k == 3) cout << "No Sales";
  return 0;
}

