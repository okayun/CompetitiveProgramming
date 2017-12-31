#include <bits/stdc++.h>

using ll = long long;

#define MOD (ll)(1e9 + 7)

// n!
ll factorial (ll n) {
  if (n == 0) return 1LL;
  return (n * factorial(n - 1)) % MOD;
}

// pow(x, n) := x^n
ll power (ll x, ll n) {
  if (n == 0) return 1LL;

  ll ret = power((x * x) % MOD, n / 2) % MOD;
  if (n % 2) ret = (ret * x) % MOD;

  return ret;
}

// x^(-1) ≡ x^(MOD - 2) (mod MOD)
ll inverse (ll x) {
  return power(x, MOD - 2);
}

// nCr
ll C (ll n, ll r) {
  if (n < r || r < 0) return 0LL;
  if (n == r) return 1LL;
  // n! / ((n - r)! * r!)
  return (((factorial(n) * inverse(factorial(r))) % MOD) * inverse(factorial(n - r))) % MOD;
}

// nPr
ll P (ll n, ll r) {
  if (n < r || r < 0) return 0LL;
  return (factorial(n) * inverse(factorial(r))) % MOD;
}

int main() {

  return 0;
}
