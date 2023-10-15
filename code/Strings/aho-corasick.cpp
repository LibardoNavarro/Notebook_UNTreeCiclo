// Usar el aho-corasick para buscar multiples patrones en un texto
const static int N=1e5; // Maximo de strings
const static int alpha = 26; // Tamano del alfabeto
int trie[N][alpha], fail[N], nodes, end_word[N], cnt_word[N], fail_out[N];
inline int conv(char ch) { // Funcion para indexar el alfabeto
  return ((ch >= 'a' && ch <= 'z') ? ch-'a' : ch-'A'+26);
}

// Para cada string, se agrega al trie O(s), peor caso O(s*n) n=numero de strings
void add(string &s, int i) {
  int act=0;
  for(char c:s) {
    int x=conv(c);
    if(!trie[act][x]) trie[act][x]=++nodes;
    act=trie[act][x];
  }
  ++cnt_word[act];
  end_word[act]=i;
}

// Se crea el trie con bfs O(N*log(ALPHA))
void build(){ 
  queue<int> q;q.push(0);
  while(sz(q)){
    int u=q.front();q.pop();
    for(int i=0;i<alpha;++i) {
      int v=trie[u][i];
      if(!v)trie[u][i]=trie[fail[u]][i]; 
      else q.push(v);
      if(!u || !v)continue;
      fail[v]=trie[ fail[u] ][i];
      fail_out[v]=end_word[fail[v]]?fail[v]:fail_out[fail[v]];
      cnt_word[v]+=cnt_word[fail[v]];
    }
  }
}

// O(n+m) donde n=tamano del texto y m=cantidad de strings
vs strings;
void searchPatterns(string &t) {
  int act=0, n=len(t);
  for(int i=0;i<n;++i) {
    int x=conv(t[i]);
    act=trie[act][x]; 
    int temp=act;
    while(temp){
      if(end_word[temp])cout<<"En la posicion "<<i<<" se encontro la palabra "<<strings[end_word[temp]-1]<<"\n";
      temp=fail_out[temp];
    }
  }
}

// Por si solo se necesita saber si esta O(s)
void solve(int index, string s){
  int act=0;
  bool pass=false;
  for(auto c:s){
    int x=c-'a';
    while(act && !trie[act][x])act=fail[act];
    act=trie[act][x]; 
    pass|=end_word[act]<index;
  }
  cout<<(pass?"YES":"NO")<<"\n";
}

int main() {
add(string, i+1); //Anadir todos los patrones
build(); // Construir el trie
searchPatterns(texto); // Buscar todos los patrones en el texto
return 0;
}