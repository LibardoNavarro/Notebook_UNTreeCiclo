// La factorizacion de Lyndon de un string es una lista de strings no vacios
// tal que el string original es la concatenacion de los strings de la lista
// en orden lexicografico. Ademas, cada string de la lista es un string de
// Lyndon, es decir, es un string que es lexicograficamente menor que todos
// sus sufijos no triviales. Por ejemplo "ab"<"ba". Tambien los strings estan
// ordenados de mayor a menor. 

// El algoritmo de Duval encuentra la factorizacion de Lyndon de un string en O(n)
vs duval(string const& s) {
  int n=len(s),i=0;
  vs factorization;
  while(i<n){
    int j=i+1,k=i;
    while(j<n && s[k]<=s[j]){
      if(s[k]<s[j])k=i;
      else k++;
      j++;
    }
    while(i<=k){
      factorization.push_back(s.substr(i, j-k));
      i+=j-k;
    }
  }
  return factorization;
}
int main() {
string s="aabaaab";
vs factorization=duval(s);
for(string& factor:factorization)cout<<factor<<"\n";
}
