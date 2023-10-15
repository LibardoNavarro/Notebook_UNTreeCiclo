// Encuentra la rotacion lexicograficamente menor de un string O(n)
int minimal_rotation(string& t) {
  int i=0,j=1,k=0,n=len(t),x,y;
  while(i<n && j<n && k<n) {
    x=i+k;y=j+k;
    if(x>=n)x-=n;
    if(y>=n)y-=n;
    if(t[x]==t[y])++k;
    else if(t[x]>t[y]){
      i=j+1>i+k+1?j+1:i+k+1;
      swap(i,j);
      k=0;
    }else{
      j=i+1>j+k+1?i+1:j+k+1;
      k=0;
    }
  }
  return i;
}

// Son lo mismo
string min_cyclic_string(string s) {
  s+=s;
  int n=len(s),i=0,ans=0;
  while(i<n/2){
    ans=i;
    int j=i+1,k=i;
    while(j<n && s[k]<=s[j]){
      if(s[k]<s[j])k=i;
      else k++;
      j++;
    }
    while(i<=k)
    i+=j-k;
  }
  return s.substr(ans, n/2);
}