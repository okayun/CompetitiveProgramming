#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

/**
 * Verifyする
*/

class TrieTree {
private:
  struct Node {
      int value;
      Node *next[0x100];
      Node() {
          fill(next, next + 0x100, (Node*)0);
      }
  };
  Node node;

public:
  TrieTree() {}

  void Make(char *t) {
      Node *r = &node;
      for (int i = 0; t[i]; ++i) {
          char c = t[i];
          if (!r->next[c]) r->next[c] = new Node;
          r = r->next[c];
      }
  }

  bool Find(char *t) {
      Node *r = &node;
      for (int i = 0; t[i]; ++i) {
          char c = t[i];
          if (!r->next[c]) {
              return false;
          }
          r = r->next[c];
      }
      return true;
  }
};

int main() {
  char str[] = "otyaduke", str2[] = "ostream", tmp[] = "ok", tmp2[] = "otya";
  TrieTree t;
  t.Make(str);
  t.Make(str2);
  cout << t.Find(tmp) << endl;
  cout << t.Find(tmp2) << endl;

  return 0;
}
