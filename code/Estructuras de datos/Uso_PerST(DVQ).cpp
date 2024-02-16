
// insertar Persistent ST de sumas 

int main() {
    ll n, k; cin >> n >> k; 
    vl vals(n, 0); 
    forx(i, n) cin >> vals[i];

    // creacion del perST
    vl basSt(n, 0);
    perST vers(basSt);
    
    // Cada ST estara guardando si el i-esimo elemento es una
    // ultima ocurrencia y la idea es crear una nueva version
    // por cada actualizacion de este dato
    map<ll, ll> lastOcur;
    for(int i = 1; i <= n; i++){
        if (!lastOcur[vals[i - 1]]){
            vers.rts.pb(vers.upd(i - 1, i - 1, 1));
            lastOcur[vals[i - 1]] = i;
        }else{
            vers.rts.pb(vers.upd(i - 1, i - 1, 1));
            vers.rts[i] = vers.upd(i, lastOcur[vals[i - 1]] - 1, 0);
            lastOcur[vals[i - 1]] = i;
        }
    }

    // Para hacer la consulta de la cantidad de
    // distintos en un rango basta con hacer una
    // tipica consulta pero en la version de b
    while(k--){
        ll a, b; cin >> a >> b;
        a--; b--;
        cout << vers.get(b + 1, a, b) << ln;
    }
}