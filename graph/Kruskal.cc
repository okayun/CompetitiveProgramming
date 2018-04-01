#include <iostream>
#include <algorithm>
#include <vector>

// または演算子オーバーロードなど
bool comp(const edge &e1, const edge &e2) {
  return e1.cost < e2.cost;
}

int kruskal(std::vector<edge>& es) {
  std::sort(es.begin(), es.end(), comp);
  UnionFind uf(V);
  int ret = 0;

  for (int i = 0; i < E; ++i) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      ret += e.cost;
    }
  }

  return ret;
}

int main() {
  return 0;
}
