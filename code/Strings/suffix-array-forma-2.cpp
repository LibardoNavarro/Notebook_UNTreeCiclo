// Construccion O(nlogn)
// Usar cuando queremos ver patron por patron, es mejor que el aho-corasick
struct SuffixArray{
  char MIN_CHAR='$';
  int ALPHA=256;
  int n;
  string s;
  vi pos, rnk, lcp;
  SuffixArray(const string &_s):n(len(_s) + 1), s(_s), pos(n), rnk(n), lcp(n-1){
    s+=MIN_CHAR;
    buildSA();
    buildLCP();
  }
 
  void buildSA(){
    vi cnt(max(ALPHA, n));
    for(int i=0;i<n;i++)cnt[s[i]]++;
    for(int i=1;i<ALPHA;i++)cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)pos[--cnt[s[i]]]=i;
    for(int i=1;i<n;i++)rnk[pos[i]]=rnk[pos[i-1]]+(s[pos[i]]!=s[pos[i-1]]);
    for(int k=0;(1<<k)<n;k++) {
      vi npos(n),nrnk(n),ncnt(n);
      for(int i=0;i<n;i++)pos[i]=(pos[i]-(1<<k)+n)%n;
      for(int i=0; i < n; i++)ncnt[rnk[i]]++;
      for(int i=1; i < n; i++)ncnt[i]+=ncnt[i-1];
      for(int i=n-1;i>=0;i--)npos[--ncnt[rnk[pos[i]]]]=pos[i];
      for(int i=1;i<n;i++){
        ii cur={rnk[npos[i]],rnk[(npos[i]+(1<<k))%n]};
        ii pre={rnk[npos[i-1]],rnk[(npos[i-1]+(1<<k))%n]};
        nrnk[npos[i]]=nrnk[npos[i-1]]+(cur!=pre);
      }
      pos=npos;rnk=nrnk;
    }
  }
 
  void buildLCP(){
    for(int i=0,k=0;i<n-1;i++,k=max(k-1,0)){
      int j=pos[rnk[i]-1];
      while(s[i+k]==s[j+k])k++;
      lcp[rnk[i]-1]=k;
    }
  }
 
  // O(logn+t)
  // Encuentra cuantas veces aparece t en s
  int cntMatching(const string &t){
    int m=len(t);
    if(m>n)return 0;
    int lo,hi,lb,ub;
    lo=0,hi=n-1;
    while(lo<hi){
      int mid=(lo+hi)/2;
      if(s.substr(pos[mid],m)>=t)hi=mid;
      else lo=mid+1;
    }
    lb=lo;lo=0,hi=n-1;
    while(lo<hi){
      int mid=(lo+hi+1)/2;
      if(s.substr(pos[mid],m)<=t)lo=mid;
      else hi=mid-1;
    }
    ub=lo;
    return s.substr(pos[lb], m)==t?ub-lb+1:0;
  }
};
 
int main() {
string s;cin>>s;
int n;cin>>n;
SuffixArray sa(s);
for(int i=0;i<n;i++){
  string t;cin>>t;
  cout<<sa.cntMatching(t)<<"\n";
}
}