#include <bits/stdc++.h>

using ll = long long;

#define MOD (ll)(1e9 + 7)
#define MAX_N 100001 // 適宜変更すること

// memo
ll fact[MAX_N], fact_inv[MAX_N];

// n!
void factorial_prepare(ll n) {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
}

// pow(x, n) := x^n
ll power(ll x, ll n) {
  if (n == 0) return 1LL;

  ll ret = power((x * x) % MOD, n / 2) % MOD;
  if (n % 2) ret = (ret * x) % MOD;

  return ret;
}

// x^(-1) ≡ x^(MOD - 2) (mod MOD)
// (x!)^(-1) ≡ (x!)^(MOD - 2) (mod MOD)
void inverse_prepare(ll x) {
  // (x!)^(-1)を求めて, その値にx, x-1, ... を順に掛ける
  fact_inv[x] = power(fact[x], MOD - 2);

  for (int i = x - 1; i >= 1; --i) {
    fact_inv[i] = ((fact_inv[i + 1] * (i + 1)) % MOD);
  }
}

// nCr, nPr の想定される最大の n で初期化
void init(ll n) {
  factorial_prepare(n);
  inverse_prepare(n);
}

// nCr
ll C(ll n, ll r) {
  if (n < r || r < 0) return 0LL;
  if (n == r || r == 0) return 1LL;
  // n! / ((n - r)! * r!)
  return (((fact[n] * fact_inv[r]) % MOD) * fact_inv[n - r]) % MOD;
}

// nPr
ll P(ll n, ll r) {
  if (n < r || r < 0) return 0LL;
  if (n == r) return (fact[n]) % MOD;
  // n! / (n - r)!
  return (fact[n] * fact_inv[n - r]) % MOD;
}

int main() {
  init(MAX_N);

  return 0;
}
