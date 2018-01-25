#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, m, T;

  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    cin >> m >> T;

    std::vector<std::string> square(m);

    for (int j = 0; j < m; j++)
    {
      cin >> square[i];
    }
  }

  return 0;
}
