// Para encontrar la subcadena comun mas larga entre dos strings O(s)
vi z_algoritm(string s){
  int n=len(s),l=0,r=0;
  vi z(n);
  for(int i=1;i<n;i++){
    z[i]=max(0, min(z[i-l], r-i+1));
    while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
      l=i,r=i+z[i],++z[i];
    }
  }
  return z;
}

int main() {
string t="abababab",p="aba";
vi z=z_algoritm(p+"$"+t);
for(int i=len(p)+1;i<sz(z);i++){
cout<<z[i]<<" ";
}cout<<"\n";
return 0;
}