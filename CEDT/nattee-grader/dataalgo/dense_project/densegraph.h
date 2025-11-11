#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

#include <iostream>
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
      n = 3;
      mat.resize(3);
      for(auto &x : mat) x.resize(3);
    }

    DenseGraph(int n_in) {
      n = n_in;
      mat.resize(n);
      for(auto &x : mat) x.resize(n);
    }

    DenseGraph(const DenseGraph& G) {
      n = G.n;
      mat = G.mat;
    }

    void AddEdge(int a, int b) {
      mat[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
      mat[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const {
      return mat[a][b];
    }

    DenseGraph Transpose() const {
      DenseGraph t(n);
      for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
          t.mat[i][j] = mat[j][i];
        }
      }
      return t;
    }

protected:
    int n;
    vector<vector<bool>> mat;
};
#endif // __DENSE_GRAPH_H__
