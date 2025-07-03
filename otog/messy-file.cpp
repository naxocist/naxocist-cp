#include <bits/stdc++.h>
using namespace std;

bool isnum(string s) {
  for(auto c : s) {
    if(c < '0' or c > '9') return 0;
  }
  return 1;
}
map<string, int> id, cnt;

int main() {
  string s; cin >> s;
  int n = s.size(); 
  stack<string> st;
  int i=0;

  while(1){
    auto nxt = s.find("/", i+1);
    if(nxt == string::npos) break ;
    string t = s.substr(i+1, nxt-i-1);
    int m = t.size();

    if(t == "." or t == "") goto l;

    if(t == "..") {
      if(st.empty()) goto l;
      string tp = st.top(); st.pop();
      goto l;
    }

    for(int i=1; i<=m; ++i) {
      string nm = t.substr(m-i,i);
      if(!isnum(nm)) break ;
      string lf = t.substr(0, m-i);
      if(cnt.find(lf) != cnt.end() and cnt[lf] + 1 == stoi(nm)) {
        // next count
        cnt[lf] ++;
        st.emplace(lf); 
        goto l;
      }
    }
    // new string
    st.emplace(t);
    cnt[t] ++;

    l:;
    i = nxt;
  }

  // i = 0;
  // while(1){
  //   auto nxt = s.find("/", i+1);
  //   if(nxt == string::npos) break ;
  //   string t = s.substr(i+1, nxt-i-1);
  //   if(t == "." or t == "") goto r;
  //   if(t == "..") {
  //     if(st.empty()) goto r;
  //     string tp = st.top(); st.pop();
  //     if(mp.find(tp) != mp.end() and mp[tp] > 0) {
  //       if(--mp[tp] == 0) mp.erase(tp);
  //     }
  //   }
  //   else st.emplace(t), mp[t] ++;

  //   r:;
  //   i = nxt;
  // }

  map<string, int> tm = id;
  // for(auto a : tm) cout << a.first << ' ' << a.second << endl;

  vector<string> v; 
  while(st.size()) {
    string t = st.top(); st.pop();
    v.emplace_back(t); 
  }

  if(v.empty()) cout << "/";
  else for(int i=v.size()-1; i>=0; --i) cout << "/" << v[i];

  return 0;
}

