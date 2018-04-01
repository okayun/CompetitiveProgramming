#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

/**
 * せっかくなので追加しておく
*/

// 座標圧縮
std::vector<int> coordinateCompression(std::vector<int>& a) {
  std::vector<int> ret, b;
  std::map<int, int> mp;
  int cnt = 0;

  b = a;

  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());

  for (int i = 0; i < b.size(); ++i) {
    mp[b[i]] = cnt++;
  }

  for (int i = 0; i < a.size(); ++i) {
    ret.push_back(mp[a[i]]);
  }

  return ret;
}

int main() {
  return 0;
}
