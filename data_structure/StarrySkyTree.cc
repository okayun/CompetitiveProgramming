#include <iostream>
#include <algorithm>
#include <vector>

/**
 * Verifyする
*/

template <typename T>
class StarrySkyTree {
private:
  int n;
  T init;
  std::vector<T> seg, __add;

  int Size (int N) {
    int ret;
    for (ret = 1; ret < N; ret <<= 1);
    return ret;
  }

  T Query(int a, int b, int k, int l, int r) {
    if (r <= a or b <= l) return int(1e9); ///
    if (a <= l and r <= b) return seg[k] + __add[k];

    T vl = Query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = Query(a, b, k * 2 + 2, (l + r) / 2, r);
    return (min(vl, vr) + __add[k]); ///
  }

  void _Add(int a, int b, int x, int k, int l, int r) {
    if (r <= a || b <= l) return; // 交差しない区間であれば終了
    if (a <= l && r <= b) { // 現在の区間が完全に内包されていればxを加算して終了
        __add[k] += x;
        return;
    }

    _add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    _add(a, b, x, k * 2 + 2, (l + r) / 2, r);

    seg[k] = min(seg[k * 2 + 1] + __add[k * 2 + 1], seg[k * 2 + 2] + __add[k * 2 + 2]); ///
  }

public:
  ///
  StarrySkyTree (int N) : n(Size(N)), seg(Size(N) * 2, 0), __add(Size(N) * 2, 0), init(0) {}

  // [l, r) 開区間であることに注意!!! ... [l, r]ならfind(l, r + 1)
  T Find(int l, int r) {
    return Query(l, r, 0, 0, n);
  }

  // [a, b) に x を「加算」する
  void Add(int a, int b, int x) {
      _Add(a, b, x, 0, 0, n);
  }
};

int main() {
  return 0;
}
