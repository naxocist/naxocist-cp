#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back

map<string, set<string>> mp;
set<string> t;
using T = tuple<string, string, string>;
stack<T> st;

void f(string s, string a, string b) {
  bool u = false;
  if (s[0] == '.')
    s = s.substr(1), u = true;

  if (s == "ADDEVENT") {
    if (mp.find(s) == mp.end())
      mp.insert({s, set<string>()});
  } else if (s == "REGISTER") {
    if (t.find(b) != t.end()) {
      if (!u)
        st.emplace("-", "", "");
    } else {
      mp[a].insert(b);
      if (!u)
        st.emplace(".CANCEL", a, b);
      t.insert(b);
    }
  } else if (s == "SHOW") {
    for (auto &x : mp[a])
      cout << x << ' ';
    cout << '\n';
  } else if (s == "CANCEL") {
    if (mp.find(a) == mp.end()) {
      if (!u)
        st.emplace("-", "", "");
      return;
    }
    auto it = t.find(b);
    auto it2 = mp[a].find(b);
    if (it != t.end() and it2 != mp[a].end()) {
      mp[a].erase(b);
      if (!u)
        st.emplace(".REGISTER", a, b);
      t.erase(it);
    } else {
      if (!u)
        st.emplace("-", "", "");
    }
  } else {
    if (st.empty())
      return;
    auto [x, y, z] = st.top();
    st.pop();
    if (x == "-")
      return;
    f(x, y, z);
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    string a = "", b = "";
    if (s != "UNDO")
      cin >> a;
    if (s == "REGISTER" or s == "CANCEL")
      cin >> b;
    // cout << s << ' ' << a << ' ' << b << '\n';
    f(s, a, b);
  }
  return 0;
}
