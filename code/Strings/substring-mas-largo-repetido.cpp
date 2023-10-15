// Implementar primero suffix-array-forma-1
string longest_repeated_substring(string& s){ //O(nlogn)
  // Si se tienen que sacar varios, entonces son todos los que sean iguales al maximo
  vi sa=suffix_array(s);
  vi lcp=lcp_construction(s,sa);
  int n=len(s);
  int max_len=0, start=0;
  for(int i=0;i<n-1;i++){
    if(lcp[i]>max_len){
      max_len=lcp[i];
      start=sa[i];
    }
  }
  return s.substr(start,max_len);
}