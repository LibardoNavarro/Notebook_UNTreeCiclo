const int N = 1e5; // Tamano del automata
const int ALPHA = 255; // Tamano del alfabeto ASCII
int automata[N][ALPHA]; // Tabla de transicion del automata

// O(s*ALPHA)
void kmp_automata(string& s){
  automata[0][s[0]] = 1;
  for(int i = 1, j = 0; i <= len(s); ++i){
    // Copiar la fila anterior
    for(int k = 0; k < ALPHA; ++k)automata[i][k] = automata[j][k];
    // Actualizar la entrada correspondiente al caracter actual
    if(i<len(s)){
      automata[i][s[i]]=i+1;
      j=automata[j][s[i]];
    }
  }
}
