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

  void Add (int k, const T& a) {
    for (; k < N; k |= k + 1) bit[k] += a;
  }

  void Set(int k, const T& a) {
    Add(k, a - Sum(k, k + 1));
  }

  // sum from 0 to k-1, [0, k)
  T Sum(int k) {
    int ret = 0;
    for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
    return ret;
  }

  // sum from l to r [l, r)
  T Sum(int l, int r) {
    return Sum(r) - Sum(l);
  }
};

int main() {
  return 0;
}
