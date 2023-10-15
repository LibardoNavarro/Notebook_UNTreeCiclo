//  a b c b a a b 
//  1 1 5 1 1 1 1  f = 0 impar
//  0 0 0 0 0 4 0  f = 1 par (raiz, izq, der)
void manacher(string &s, int f, vi &d){ // O(s)
  int l=0, r=-1, n=len(s);
  d.assign(n,0);
  for(int i=0;i<n;++i){
    int k=(i>r?(1-f):min(d[l+r-i+ f], r-i+f))+f;
    while(i+k-f<n && i-k>=0 && s[i+k-f]==s[i-k])++k;
    d[i]=k-f;--k;
    if(i+k-f>r)l=i-k,r=i+k-f;
  }
  for(int i=0;i<n;++i)d[i]=(d[i]-1+f)*2+1-f;
}

int main() {
string s;cin>>s;
vi manacher_odd, manacher_even;
manacher(s, 0, manacher_odd);
manacher(s, 1, manacher_even);
for(int i=0;i<len(s);++i){
  if(manacher_odd[i]==0 || manacher_odd[i]==1)continue;
  cout<<s.substr(i-manacher_odd[i]/2, manacher_odd[i])<<" ";
}
cout<<"\n";
for(int i=0;i<len(s);++i){
  if(manacher_even[i]==0)continue;
  cout<<s.substr(i-manacher_even[i]/2, manacher_even[i])<<" ";
}
cout<<"\n";
}