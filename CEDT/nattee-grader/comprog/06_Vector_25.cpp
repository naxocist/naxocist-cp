#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  vector<string> grade = {"F", "D", "D+", "C", "C+", "B", "B+", "A"};

  vector<string> name;
  vector<int> gr;

  string s, g;
  while(cin >> s) {
    if(s == "q") break ;
    cin >> g;
    name.pb(s);
    int gi = find(all(grade), g) - begin(grade);
    gr.pb(gi);
  }

  while(cin >> s) {
    int idx = find(all(name), s) - begin(name);
    gr[idx] ++; gr[idx] = min(gr[idx], (int)grade.size() - 1);
  }

  for(int i=0; i<(int)name.size(); ++i) {
    cout << name[i] << ' ' << grade[gr[i]] << ln;
  }
  return 0;
}

