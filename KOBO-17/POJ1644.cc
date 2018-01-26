#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

typedef long long ll;

int N, m, T;
ll memo[53][42];
std::vector<std::string> s;

ll solve(int pos, int turn) {
  if (turn > T) {
    if (pos == m + 1) {
      return 1LL;
    }
    else {
      return 0LL;
    }
  }

  if (memo[pos][turn] != -1) {
    return memo[pos][turn];
  }

  ll ret = 0;

  if (pos == m + 1) {
    ret += (solve(pos, turn + 1) * 2);
  }
  else {
    int npos = std::min(pos + 1, m + 1), inst;
    bool flag = (s[npos] == "L");
    inst = ((flag || s[npos] == "0") ? 0 : ((s[npos][0] == '-' ? -1 : 1) * std::atoi(&s[npos][1])));
    npos += inst;
    npos = std::max(std::min(npos, m + 1), 0);

    if (flag) {
      ret += solve(npos, turn + 2) * 2;
    }
    else {
      ret += solve(npos, turn + 1);
    }

    npos = std::min(pos + 2, m + 1);
    flag = (s[npos] == "L");
    inst = ((flag || s[npos] == "0") ? 0 : ((s[npos][0] == '-' ? -1 : 1) * std::atoi(&s[npos][1])));
    npos += inst;
    npos = std::max(std::min(npos, m + 1), 0);

    if (flag) {
      ret += solve(npos, turn + 2) * 2;
    }
    else {
      ret += solve(npos, turn + 1);
    }
  }

  return memo[pos][turn] = ret;
}

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  cout << std::fixed;
  cout.precision(4);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> m >> T;
    s.resize(m + 2, "0");

    for (int i = 1; i <= m; ++i) {
      cin >> s[i];
    }

    std::memset(memo, -1, sizeof memo);

    ll res = solve(0, 1), M = (1LL << T);

    if (res * 2 == M) {
      cout << "Push. ";
    }
    else if (res * 2 > M) {
      cout << "Bet for. ";
    }
    else {
      cout << "Bet against. ";
    }
    cout << double(res) / M << "\n";

    s.clear();
  }

  return 0;
}
