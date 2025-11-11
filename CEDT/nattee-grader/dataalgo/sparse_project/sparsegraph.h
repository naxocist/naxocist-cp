#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__


#include <vector>
#include <set>
using namespace std;

class SparseGraph{
public:
    SparseGraph() {
      adj.resize(3);
    }

    SparseGraph(int n_in) {
      adj.resize(n_in);
    }

    SparseGraph(const SparseGraph& G) {
      adj = G.adj;
    }

    void AddEdge(int a, int b) {
      adj[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
      adj[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
      for(auto &x : adj[a]) {
        if(b == x) return true;
      }
      return false;
    }

    SparseGraph Transpose() const {
      SparseGraph t((int)adj.size());

      for(int i=0; i<(int)adj.size(); ++i) {
        for(auto &j : adj[i]) {
          t.adj[j].insert(i);
        }
      }

      return t;
    }

protected:
    vector<set<int>> adj;
};
#endif // __SPARSE_GRAPH_H__

