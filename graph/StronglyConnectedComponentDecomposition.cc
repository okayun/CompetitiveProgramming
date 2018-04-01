#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

// Strongly Connected Component Decomposition
class SCC {
private:
  int n;
  std::vector<std::vector<int> > g, rg;
  std::vector<int> cmp;
  std::vector<bool> used;
  std::stack<int> st;

public:
  SCC(int V) : n(V), g(V), rg(V), cmp(V), used(V, false) {}

  void addEdge(int from, int to) {
    g[from].push_back(to);
    rg[to].push_back(from);
  }

  // あとでラムダ式verに書き直す
  void dfs(int v) {
    used[v] = true;
    int size_ = g[v].size();

    for (int i = 0; i < size_; ++i) {
      if (!used[g[v][i]]) dfs(g[v][i]);
    }

    st.push(v);
  }

  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    int size_ = rg[v].size();

    for (int i = 0; i < size_; ++i) {
      if (!used[rg[v][i]]) rdfs(rg[v][i], k);
    }

    st.push(v);
  }

  // 分解
  int scc() {
    for (int i = 0; i < n; ++i) if (!used[i]) dfs(i);

    used.assign(n, false);

    int k = 0;

    while (!st.empty()) {
      if (!used[st.top()]) rdfs(st.top(), k++);
      st.pop();
    }

    return k;
  }

  // 頂点xと頂点yが同じ連結成分に属しているかどうか
  bool same(int x, int y) {
    return (cmp[x] == cmp[y]);
  }
};

int main() {
  return 0;
}
