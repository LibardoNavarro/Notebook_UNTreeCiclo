/// Complexity: |N|*log(|N|)
/// Tested: Not yet.
/// finds a suitable x that meets: x is congruent to a_i mod n_i
/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L = LCM of mods
*/

pll crt( vl A, vl M ) {
  ll n = A.size(), a1 = A[0], m1 = M[0];
  for(ll i = 1; i < n; i++) {
    ll a2 = A[i], m2 = M[i];
    ll g = __gcd(m1, m2);
    if( a1 % g != a2 % g ) return {-1,-1};
    ll p, q;
    extended_euclid(m1/g, m2/g, p, q);
    ll mod = m1 / g * m2;
    q %= mod; p %= mod;
    ll x = ((1ll*(a1%mod)*(m2/g))%mod*q + (1ll*(a2%mod)*(m1/g))%mod*p) % mod; // if WA there is overflow
    a1 = x;
    if (a1 < 0) a1 += mod;
    m1 = mod;
  }
  return {a1, m1};
}