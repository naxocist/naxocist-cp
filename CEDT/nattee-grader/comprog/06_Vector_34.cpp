#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  vector<int> id, t;

  int base = -1;

  int crrid = -1, crrt = -1;
  double sum = 0; int cnt = 0;
  while(n--) {
    string op; int x; cin >> op;
    if(op != "avg_qtime" and op != "next") cin >> x;

    if(op == "reset") base = x;

    if(op == "new") {
      cout << ">> ticket " << base << ln;
      id.pb(base++);
      t.pb(x);
    }

    if(op == "next") {
      cout << ">> call " << id.front() << ln;
      crrid = id.front(), crrt = t.front();
      id.erase(begin(id));
      t.erase(begin(t));
    }

    if(op == "order") {
      cout << ">> qtime " << crrid << ' ' << x - crrt << ln;
      sum += x - crrt;
      cnt ++;
    }

    if(op == "avg_qtime") {
      double avg = sum/cnt; avg = round(avg*100.0)/100.0;
      cout << ">> avg_qtime "  << avg << ln;
    }
  }
  return 0;
}

