#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#define INF int(1e9 + 7)

template <typename T>
class SegmentTree {
private:
  int n;
  T init_;
  std::vector<T> seg;
  std::function<T(T, T)> compare = [](T a, T b){ return (a < b) ? a : b; }; // min

  int size (int N) {
    int ret;
    for (ret = 1; ret < N; ret <<= 1);
    return ret;
  }
 
  T query(int a, int b, int k, int l, int r) {
    if (r <= a or b <= l) return init_;
    if (a <= l and r <= b) return seg[k];
 
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return compare(vl, vr);
  }
 
public:
  SegmentTree (int N, T i) : n(size(N)), seg(size(N) * 2, i), init_(i) {}
  SegmentTree () {}
 
  void Init(int N, T i) {
    n = size(N);
    seg.resize(size(N) * 2 - 1, i);
    init_ = i;
  }
 
  void Update (int k, T val) {
    k += n - 1;
    seg[k] = val;
    while (k > 0) {
      k = (k - 1) / 2;
      // 適宜変更
      seg[k] = compare(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
 
  // [l, r) 開区間であることに注意!!! ... [l, r]ならfind(l, r + 1)
  T Find(int l, int r) {
    return query(l, r, 0, 0, n);
  }
};

int main() {
  SegmentTree<std::pair<int, int> > segtree;
  segtree.Init(8, {INF, INF});

  for (int i = 0; i < 8; ++i) {
    segtree.Update(i, {i + 1, i});
  }

  auto p = segtree.Find(0, 8);
  cout << p.first << " " << p.second << endl;

  p = segtree.Find(0, 4);
  cout << p.first << " " << p.second << endl;

  p = segtree.Find(2, 6);
  cout << p.first << " " << p.second << endl;
  /* */
  return 0;
}
