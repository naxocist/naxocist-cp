#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

vector<string> name;
vector<double> vote;

vector<int> people;
vector<double> vleft;


bool cmp(int i, int j) {
  if(people[i] != people[j]) return people[i] > people[j];

  return vote[i] > vote[j];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 

  string s; double v;

  double p = 0;
  while(cin >> s) {
    if(s == "END") break ;
    cin >> v;
    name.pb(s); vote.pb(v);
    p += v;
  }

  int n = name.size();

  p /= 100;

  int cnt = 0;
  for(auto x : vote) {
    double t = x / p; 
    int pp = t;
    double left = t - pp;
    vleft.pb(left);
    people.pb(pp);

    cnt += pp;
  }

  vector<double> tmp(vleft);
  sort(rbegin(tmp), rend(tmp));


  for(int i=0; i<n and cnt ++ < 100; ++i) {
    int idx = find(all(vleft), tmp[i]) - begin(vleft);
    people[idx] ++;
  }

  vector<int> st(n);
  for(int i=0; i<n; ++i) st[i] = i;
  sort(all(st), cmp);

  for(int j=0; j<n; ++j) {
    int i = st[j];
    if(people[i]) cout << name[i] << ' ' << people[i] << ' ' << (int)vote[i] << ln;
  }
  return 0;
}

