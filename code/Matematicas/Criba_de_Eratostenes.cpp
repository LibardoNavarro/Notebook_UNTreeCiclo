// O(N log log N)
ll _sieve_size;
bitset<10000010> bs;    //10^7 es el limite aprox
vl p;                   //Lista compacta de primos
void sieve(ll upperbound) {         //Rango = [0..limite]
    _sieve_size = upperbound+1;     //Para incluir al limite
    bs.set();                       //Todo unos
    bs[0] = bs[1] = 0;              //0 y 1 (no son primos)
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);             //Anadir primo i a la lista
    }
}