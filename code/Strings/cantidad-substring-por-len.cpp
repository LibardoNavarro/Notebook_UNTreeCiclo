// Implementar primero suffix-array-forma-2 y meter la funcion dentro
// O(n)
void numeroSubstringsPorTamano(){
  vl ps(n+1);
  for(int i=1;i<n;i++){
    int l=lcp[i-1]+1;
    int r=n-1-pos[i];
    ps[l]++; 
    ps[r+1]--;
  }   
  for(int i=1;i<n;i++) {
    ps[i]+=ps[i-1];
  }
  for(int i=1;i<n;i++) {
    cout<<ps[i]<<" ";
  }
}