const int N = 1e6;
int f[N], fr[N];
void initC(){
  f[0] = 1;
  for(int i=1; i<N; i++) f[i] = mul(f[i-1], i);
  fr[N-1] = inv(f[N-1]);
  for(int i=N-1; i>=1; --i) fr[i-1] = mul(fr[i], i);
}
// mint C(int n, int k) { return k<0 || k>n ? 0 : f[n] * fr[k] * fr[n-k]; }
struct LagrangePol {
  int n;
  vi y, den, l, r;
  LagrangePol(vector<int> f): n(sz(f)), y(f), den(n), l(n), r(n){// f[i] := f(i) 
    // Calcula interpol. pol P in O(n) := deg(P) = sz(v)-1 
    initC();
    for (int i = 0; i<n; i++) {
      den[i] = mul(fr[n-1-i], fr[i]);
      if((n-1-i) & 1) den[i] = mod(-den[i]);
    }
  }
  int eval(int x){ // Evaluate LagrangePoly P(x) in O(n)
    l[0] = r[n-1] = 1;
    for (int i = 1; i<n; i++) l[i] = mul(l[i-1], mod(x - i + 1));
    for(int i=n-2; i>=0; --i) r[i] = mul(r[i+1], mod(x - i - 1));
    int ans = 0;
    for (int i = 0; i<n; i++) ans = add(ans, mul(mul(l[i], r[i]), mul(y[i], den[i])));
    return ans;
  }
};

////////////////////////////////////////
// Para Xs que no sean de [0, N]
/// Complexity: O(|N|^2)
/// Tested: https://tinyurl.com/y23sh38k
vector<lf> X, F;
lf f(lf x) {
  lf answer = 0;
  for(int i = 0; i < sz(X); i++) {
    lf prod = F[i];
    for(int j = 0; j < sz(X); j++) {
      if(i == j) continue;
      prod = mul(prod, divide(sbt(x, X[j]), sbt(X[i], X[j])));
    }
    answer = add(answer, prod);
  }
  return answer;
}

//given y=f(x) for x [0,degree]
vi interpolation( vi &y ) {
  int n = sz(y);
  vi u = y, ans( n ), sum( n );
  ans[0] = u[0], sum[0] = 1;
  for( int i = 1; i < n; ++i )
  {
    int inv = binpow( i, MOD - 2 );
    for( int j = n - 1; j >= i; --j )
      u[j] = 1LL * (u[j] - u[j - 1] + MOD) * inv % MOD;
 
    for( int j = i; j > 0; --j )
    {
      sum[j] = (sum[j - 1] - 1LL * (i - 1) * sum[j] % MOD + MOD) % MOD;
      ans[j] = (ans[j] + 1LL * sum[j] * u[i]) % MOD;
    }
    sum[0] = 1LL * (i - 1) * (MOD - sum[0]) % MOD;
    ans[0] = (ans[0] + 1LL * sum[0] * u[i]) % MOD;
  }
  return ans;
}