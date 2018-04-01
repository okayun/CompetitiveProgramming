#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

// 適宜変更
#define MAX_V 100001

// 始点をsとして, sからtへの最短経路を求める
int dijkstra (std::vector<std::vector<edge> > g, int s, int t) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
  int d[MAX_V];

  fill(d, d + V, 0x7f);
  d[s] = 0;
  que.push(make_pair(0, s));

  while(!que.empty()) {
    pair<int, int> p = que.top();
    que.pop();
    int v = p.second, size_ = g[v].size();

    if (d[v] < p.first) continue;

    for (int i = 0; i < size_; ++i) {
      edge e = g[v][i];
      if (d[e.v] > d[v] + e.cost) {
        d[e.v] = d[v] + e.cost;
        que.push(make_pair(d[e.v], e.v));
      }
    }
  }
}


int main() {
  return 0;
}
