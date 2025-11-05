// node(const T &data, node *prev, node *next)
//         : data(T(data)), prev(prev), next(next) {}


void replace(const T& x, list<T>& y) {
  list<T> nw;
  for(auto it = begin(); it != end(); it++) {
    if(*it == x) {
      for(auto k = y.begin(); k != y.end(); k++) {
        nw.push_back(*k);
      }
      continue ;
    }
    nw.push_back(*it);
  }

  clear();
  for(auto it = nw.begin(); it != nw.end(); it++) {
    push_back(*it);
  }
}
