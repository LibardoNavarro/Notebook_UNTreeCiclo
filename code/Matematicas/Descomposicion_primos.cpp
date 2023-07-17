ll _sieve_size;
bitset<10000010> bs;
vl p;
void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);
    }
}
// O( sqrt(N) / log(sqrt(N)) )
vl primeFactors(ll N) {
    vl factors;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)
        while (N%p[i] == 0) {       //Hallado un primo para N
            N /= p[i];              //Eliminarlo de N
            factors.push_back(p[i]);
        }
    if (N != 1) factors.push_back(N);//El N restante es primo
    return factors;
}
int main(){
    sieve(10000000);
}

//Variantes del algoritmo

//Contar el numero de divisores de N
int numDiv(ll N) {
    int ans = 1;    //Empezar con ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        int power = 0;  //Contar la potencia
        while (N%p[i] == 0) { N /= p[i]; ++power; }
        ans *= power+1; //Seguir la formula
    }
    return (N != 1) ? 2*ans : ans;  //Ultimo factor = N^1
}

//Suma de los divisores de N
//N = a^i * b^i * ... * c^k => N = (a^(i+1) - 1) / (a-1) + ...
ll sumDiv(ll N) {
    ll ans = 1;         // empezar con ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        ll multiplier = p[i], total = 1;
        while (N%p[i] == 0) {
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }                                   // total para
        ans *= total;                       // este factor primo
    }
    if (N != 1) ans *= (N+1);   // N^2-1/N-1 = N+1
    return ans;
}