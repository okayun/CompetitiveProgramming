#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

// 最長共通部分列 ... len(s) == m, len(t) == n とすると, O(mn)
int lcs(std::string s, std::string t) {
  std::vector<std::vector<int> > dp(s.size() + 1, std::vector<int>(t.size() + 1, 0));

  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 1; j <= t.size(); ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else if (dp[i - 1][j] >= dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  return dp[s.size()][t.size()];
}

int main() {
  std::string s, t;

  cin >> s >> t;

  cout << lcs(s, t) << endl;

  return 0;
}
