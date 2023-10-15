// Implementar primero suffix-array-forma-1
int different_substrings(string s) { //O(nlogn)
  vi sa=suffix_array(s);
  vi lcp=lcp_construction(s,sa);
  int n=len(s);
  int act=n*(n+1);act/=2;
  for(int i=0;i<n-1;i++)act-=lcp[i];
  return act;
}

// Otra forma con hashing O(n^2)
int count_unique_substrings(string const& s) {
  int n = s.size();
  // Ojo con p y m
  const int p=31;
  const int m=1e9+9;
  ll p_pow[n], h[n+1];
  p_pow[0]=1;
  // Precalculo de potencias de p
  for(int i=1;i<n;i++)p_pow[i]=(p_pow[i-1]*p)%m;
  // Precalculo de hashes de prefijos de s
  for(int i=0;i<n;i++)h[i+1]=(h[i]+(s[i]-'a'+1)*p_pow[i])%m;
  int cnt=0;
  for(int l=1;l<=n;l++) {
    unordered_set<ll> hs;
    for(int i=0;i<=n-l;i++) {
      ll cur_h=(h[i+l]+m-h[i])%m;
      cur_h=(cur_h*p_pow[n-i-1])%m;
      hs.insert(cur_h);
    }
    cnt+=hs.size();
  }
  return cnt;
}