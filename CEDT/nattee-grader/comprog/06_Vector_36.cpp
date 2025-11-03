#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

vector<string> name;
vector<int> gr, ord;

bool cmp(int i, int j) {
  if(gr[i] != gr[j]) return gr[i] > gr[j];
  return ord[i] < ord[j];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  vector<string> grade = {"F", "D", "D+", "C", "C+", "B", "B+", "A"};


  string s, g;
  int n; cin >> n;
  while(n--) {
    cin >> s >> g;
    name.pb(s);
    int gi = find(all(grade), g) - begin(grade);
    gr.pb(gi);
  }

  for(int i=0; i<name.size(); ++i) ord.pb(i);

  while(cin >> s) {
    char c = s.back();
    s = s.substr(0, s.size()-1);

    int idx = find(all(name), s) - begin(name);
    gr[idx] += c == '+' ? 1 : -1; 
    gr[idx] = min(gr[idx], (int)grade.size() - 1);
    gr[idx] = max(gr[idx], 0);
  }

  vector<int> idx;
  for(int i=0; i<name.size(); ++i) idx.pb(i);

  sort(all(idx), cmp);

  for(int j=0; j<name.size(); ++j) {
    int i = idx[j];
    cout << name[i] << ' ' << grade[gr[i]] << ln;
  }

  return 0;
}

