#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define psi pair<string, int>
#define pb emplace_back

bool no_print = 1;

void print(int no, string code, string airport = "", int gate = 0) {
  no_print = 0;
  if(code == "CANCEL") {
    cout << no << ' ' << code << ln; 
    return ;
  }

  cout << no << ' ' << code << ' ' << airport << "[" << gate << "]" << ln;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, f; cin >> n >> f;

  map<int, string> pos; // pos on the line
  map<string, int> where;
  map<string, vector<psi>> gates_list; // airport : {<airport, gatesz>, <airport2, gatesz2>, ...}
  map<string, string> gates;
  map<string, string> base; // base of that airport (even after merged)

  for(int i=0; i<n; ++i) {
    string name, g; int p; cin >> name >> p >> g;
    pos[p] = name; where[name] = p;

    gates_list[name].push_back({name, (int)g.size()});
    gates[name] = g;

    base[name] = name;
  }

  for(int h=0; h<f; ++h) {
    string a; cin >> a;

    if(a == "MERGE") {
      int x; cin >> x;

      vector<set<string>> nw;
      int pv = -1e9;
      for(auto [p, ap] : pos) {
        if(p - pv > x) {
          pv = p;
          set<string> t = {ap};
          nw.pb(t);
          continue ;
        }
        nw.back().insert(ap);
      }

      map<int, string> nw_pos;
      for(auto s : nw) {
        auto t = s.begin();
        string head = *t;
        nw_pos[where[head]] = head;

        for(t ++; t != s.end(); ++t) {
          for(auto el : gates_list[*t]) {
            gates_list[head].pb(el);
            base[el.first] = head;
          }

          gates[head] += gates[*t];
        }
      }

      pos = nw_pos;
      h--;
      continue ;
    }

    string b; cin >> b;

    string s = a.substr(0,3), t = b.substr(0,3);
    int xs = stoi(a.substr(4, a.find(']') - 4)), xt = stoi(b.substr(4, b.find(']') - 4));

    bool closely = base[s] == base[t];

    for(auto &[airport, sz] : gates_list[base[s]]) {
      if(airport == s) break ;
      xs += sz;
    }

    for(auto &[airport, sz] : gates_list[base[t]]) {
      if(airport == t) break ;
      xt += sz;
    }

    s = base[s];
    t = base[t];

    string &stat_s = gates[s], &stat_t = gates[t];

    // SUCCESS flight
    stat_s[xs] = '0';
    if(stat_t[xt] == '0') {
      stat_s[xs] = '0';
      stat_t[xt] = '1';
      if(closely) print(h, "ROUND", t, xt);
      continue ;
    }
    
    int go = -1, mn = INT_MAX;
    for(int i=0; i<(int)stat_t.size(); ++i) {
      if(stat_t[i] == '1') continue ;

      int d = abs(i - xt);
      if(d < mn) mn = d, go = i;
      else if(d == mn) go = min(go, i);
    }

    // all gates are full
    if(go == -1) {
      stat_s[xs] = '1';
      print(h, "CANCEL");
      continue ;
    }

    stat_s[xs] = '0';
    stat_t[go] = '1';

    if(closely) print(h, "ROUND_SHIFT", t, go);
    else print(h, "SHIFT", t, go);
  }

  if(no_print) cout << "NO CHANGE";
  return 0;
}

/*

*/
