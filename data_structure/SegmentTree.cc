#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/**
 * 動作確認 >> まだ <<
*/

template <typename T>
class SegmentTree {
private:
  int n;
  T _init;
  std::vector<T> seg;
  std::function<T(T, T)> comp;

  int size(int N) {
    int ret;
    for (ret = 1; ret < N; ret <<= 1);
    return ret;
  }

  T query(int a, int b, int k, int l, int r) {
    if (r <= a or b <= l) return _init;
    if (a <= l and r <= b) return seg[k];

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return comp(vl, vr);
  }

public:
  // 比較関数はデフォルトではmin 適宜変更すること
  SegmentTree(int N, T i = 0, std::function<T(T, T)> f = [](T a, T b) { return (a < b ? a : b); })
    : n(size(N)), seg(size(N) * 2, i), _init(i), comp(f) {}
  SegmentTree() {}

  void Init(int N, T i) {
    n = size(N);
    seg.resize(size(N) * 2 - 1, i);
    _init = i;
  }

  void Update(int k, T val) {
    k += n - 1;
    seg[k] = val;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = comp(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }

  // [l, r) 開区間であることに注意!!! ... [l, r]ならfind(l, r + 1)
  T Find(int l, int r) {
    return query(l, r, 0, 0, n);
  }
};

int main() {
  return 0;
}
