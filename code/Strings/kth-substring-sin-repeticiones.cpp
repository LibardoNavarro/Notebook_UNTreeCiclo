// Implementar primero suffix-array-forma-2 y meter la funcion dentro
// El k-esimo substring lexicografico sin repeticiones O(n)
  string kthSubstr(ll k){
    for(int i=1;i<n;i++){
      int nxt=n-1-pos[i]-lcp[i-1];
      if(k>nxt){
        k-=nxt;
      }else{
        return s.substr(pos[i], k + lcp[i-1]);
      }
    }
  }