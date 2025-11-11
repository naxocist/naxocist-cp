#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using namespace std;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
  stack<vector<queue<int>>> t;
  while(a.size()) {
    vector<queue<int>> vq = a.top(); a.pop();
    for(auto &x : vq) {
      queue<int> q;
      while(x.size()) {
        int y = x.front() == from ? to : x.front();
        q.emplace(y); x.pop();
      }
      while(q.size()) x.emplace(q.front()), q.pop();
    }

    t.push(vq);
  }

  while(t.size()) {
    a.push(t.top()); t.pop();
  }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
  for(auto &[x, y] : a) {
    auto &[u, v] = y;
    v = (v == from) ? to : v;
    priority_queue<int> nu;
    while(u.size()) {
      int t = u.top(); u.pop();
      nu.emplace(t == from ? to : t);
    }
    u = nu;
  }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
  std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> b;

  for(auto &u : a) {
    auto &[x, y] = u;
    list<int> nx;
    for(auto &l : x) {
      nx.push_back(l == from ? to : l);
    }

    map<int, pair<int, string>> ny;
    for(auto [o, p] : y) {
      int no = (o == from) ? to : o;
      p.first = (p.first == from) ? to : p.first;
      ny[no] = p;
    }
    b.emplace(nx, ny);
  }

  a.swap(b);
}

#endif
