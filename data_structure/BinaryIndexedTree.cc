#include <iostream>
#include <algorithm>
#include <vector>

// BITはTにする意味あまりないような…
template<typename T>
class BIT {
private:
  int N;
  std::vector<T> bit;

public:
  // bit を i で初期化する
  BIT(int N, T i) : N(N), bit(N, i) {}

  void add (int k, const T& a) {
    for (; k < N; k |= k + 1) bit[k] += a;
  }

  void set(int k, const T& a) {
    add(k, a - sum(k, k + 1));
  }

  // sum from 0 to k-1, [0, k)
  T sum(int k) {
    int ret = 0;
    for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
    return ret;
  }

  // sum from l to r [l, r)
  T sum(int l, int r) {
    return sum(r) - sum(l);
  }
};

int main() {
  return 0;
}
