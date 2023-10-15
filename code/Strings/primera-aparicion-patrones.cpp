// Implementar primero suffix-automata-forma-2 y meter la funcion dentro
// La primera aparicion de t en s O(t)
int firstMatching(const string &t) {
  int act=0;
  for(char c:t){
    int cc=c-'a';
    if(!nxt[act][cc])return -1;
    act=nxt[act][cc];
  }
  return firstPos[act]-sz(t)+1;
}