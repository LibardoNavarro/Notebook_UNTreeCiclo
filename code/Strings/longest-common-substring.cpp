// Implementar primero suffix-automata-forma-1
// Retorna la subcadena comun mas larga entre S y T O(S+T)
string lcs(string S,string T){
  sa_init();
  for(int i=0;i<sz(S);i++)sa_extend(S[i]);
  int v=0,l=0,best=0,bestpos=0;
  for (int i=0;i<sz(T);i++){
    while(v && !st[v].next.count(T[i])){
      v=st[v].link;
      l=st[v].len;
    }
    if(st[v].next.count(T[i])){
      v=st[v].next[T[i]];
      l++;
    }
    if(l>best){
      best=l;
      bestpos=i;
    }
  }
  return T.substr(bestpos-best+1,best);
} 