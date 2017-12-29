#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using ll = long long;
//typedef long long ll;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#define INF ((1LL << 31) - 1)
#define INFLL ((1LL << 62) - 1)
#define MOD (ll)(1e9+7)
#define repi(i,j,n) for(int i = (j); i < (n); ++i)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

int vx[4] = {-1, 0, 1, 0}, vy[4] = {0, -1, 0, 1};
//int vx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, vy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

// [sx, se), [sy, ey)であることに注意
inline bool check(int sx, int ex, int sy, int ey, int x, int y) {
  return (sx <= x and x < ex and sy <= y and y < ey);
}

inline bool check(int ex, int ey, int x, int y) {
  return check(0, ex, 0, ey, x, y);
}

inline void init() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
}

int main() {

  return 0;
}
