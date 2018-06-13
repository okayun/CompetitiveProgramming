#include <iostream>
#include <algorithm>
#include <vector>

class UnionFind {
private:
  int size_;
  std::vector<int> par, rank;
  
public:
  UnionFind() : size_(0), par(std::vector<int>(0)), rank(std::vector<int>(0)) {}
  UnionFind(int size_) : size_(size_) {
    par.resize(size_), rank.resize(size_);
    rep(i,size_) par[i] = i, rank[i] = 0;
  }
  
  // 現在のsize_を返す
  int Size() { return size_; }
  
  // 親を返す
  int Root(int x) { return (par[x] == x) ? x : par[x] = Root(par[x]); }
  
  // ２つの頂点を連結する
  void Unite(int x, int y) {
    x = Root(x), y = Root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  
  // 親が同じかを判定する
  bool Same(int x, int y) { return Root(x) == Root(y); }
};

int main() {
  return 0;
}
