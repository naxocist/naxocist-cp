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
  cin.ignore();

  map<string, vector<string>> mp;
  while(n --) {
    string s; getline(cin, s);
    int id = s.find(',');
    string song = s.substr(0, id), name = s.substr(id + 2);
    mp[song].pb(name);
  }


  string t; getline(cin, t);
  int cc = 0;
  for(int i=0; i<(int)t.size();) {
    int k = t.find(',', i); 
    string z = t.substr(i, k-i);
    i = k + 2;
    cout << z << " -> ";

    bool ok = 0;
    vector<string> res = mp[z];

    if(res.empty()) cout << "Not found";
    else for(int j=0; j<(int)res.size(); ++j) {
      if(j) cout << ", ";
      cout << res[j];
    }

    cout << ln;
    if(k == -1) break ;
  }

  return 0;
}

