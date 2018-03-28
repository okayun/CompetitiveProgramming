#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

/*
        back
         |
left -- top -- right -- bottom
         |
       front
*/
struct Dice {
  int top, bottom, right, left, front, back;

  Dice() {}
  Dice(int t, int bt, int r, int l, int f, int bc)
    : top(t), bottom(bt), right(r), left(l), front(f), back(bc) {}

  /**
  * dir := 0 (90° front方向へ回転)
  * dir := 1 (90° right方向へ回転)
  * dir := 2 (90° back方向へ回転)
  * dir := 3 (90° left方向へ回転)
  */
  void rotate(int dir) {
    int tmp;

    if (dir == 0) {
      tmp = front;
      front = top;
      top = back;
      back = bottom;
      bottom = tmp;
    }
    else if (dir == 1) {
      tmp = right;
      right = top;
      top = left;
      left = bottom;
      bottom = tmp;
    }
    else if (dir == 2) {
      tmp = back;
      back = top;
      top = front;
      front = bottom;
      bottom = tmp;
    }
    else if (dir == 3) {
      tmp = left;
      left = top;
      top = right;
      right = bottom;
      bottom = tmp;
    }
  }

  void print() {
    cerr << "         " << back << "\n\n         |\n\n" << left << "    --  " << top << "  --   " << right << "   --   " << bottom << "\n\n         |\n\n         " << front << endl;
  }
};

int main() {
  Dice dice(0, 1, 2, 3, 4, 5); // こんな感じ
  dice.rotate(1);
  dice.print();
  
  return 0;
}
