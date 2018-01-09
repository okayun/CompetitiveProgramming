#include <iostream>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

/* operator[] の使い方 */
template <typename T>
class Test {
private:
  T a[100001];
  size_t size_;

public:
  Test() {
    size_ = 0;
  }

  void push (T x) {
    a[int(size_++)] = x;
  }

  size_t size () {
    return size_;
  }

  T operator[] (int index) {
    assert(0 <= index && index < int(size_));
    return a[index];
  }
};
/* operator[] の使い方 */

int main() {

  /* operator[] begin */
  Test<int> t;

  t.push(10);
  t.push(30);
  t.push(-5);
  t.push(0);

  cout << "size = " << t.size() << endl;

  for (int i = 0; i < t.size(); ++i) {
    cout << "t[" << i << "] = " << t[i] << endl;
  }
  /* operator[] end */

  return 0;
}
