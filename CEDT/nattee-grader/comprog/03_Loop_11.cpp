#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  double x;
  double s = 0;
  int t=0;
  while(1) {
    cin >> x;
    if(x == -1) break ;
    s += x;
    t ++;
  }

  if(!t) cout << "No Data", exit(0);
  s =  round(s/t*100)/100;
  cout << s;
  return 0;
}

