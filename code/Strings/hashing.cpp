// se recomienda usar m = pow(2,64) porque 
// m=1e9+9 no es suficiente para la multiplicacion de dos 64-bit integers
// Porque la probabilidad de colisiones es 1/m = 10^-9
// y si son 10^6 strings que hay que comparar con este entonces 1/m = 10^-3
// y comparamos unos con otros entonces 1/m = 1, si o si va a haber algun fallo
// Una solucion sencilla es hacer dos hash (hash1, hash2) 
// con p diferentes para tener una probabilidad de 1/10^18
// y si comparamos unos con otros entonces 1/m = 10^-6

// Dos strings con mismo hash no necesariamente son iguales
// Pero si tienen distinto hash, entonces son distintos
ll compute_hash(string const& s) { // O(n)
  const int p = 31; // 51 si se usan mayusculas tambien
  // Importante que m sea un numero primo
  const int m = 1e9 + 9; 
  ll hash_value=0;
  ll p_pow=1;
  for (char c:s) {
    hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
    p_pow=(p_pow*p)%m;
  }
  return hash_value;
}

// O(n(m+logn)) n=cantidad de strings, m=tamano del string mas largo
vector<vi> group_identical_strings(vs const& s) {
  int n=s.size();
  vector<pair<ll, int>> hashes(n);
  for(int i=0;i<n;i++)
    hashes[i]={compute_hash(s[i]),i};
  sort(all(hashes));
  vector<vi> groups;
  for(int i=0;i<n;i++) {
    // Si es el primero o si el hash es distinto al anterior entonces es un nuevo grupo
    if(i==0 || hashes[i].first!=hashes[i-1].first)groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }
  return groups;
}
