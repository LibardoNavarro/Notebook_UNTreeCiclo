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

vl primeFactors(ll N) {
    vl factors;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)
        while (N%p[i] == 0) {
            N /= p[i];
            factors.push_back(p[i]);
        }
    if (N != 1) factors.push_back(N);
    return factors;
}
int main(){
    sieve(10000000);
}

//Variantes del algoritmo

//Contar el numero de factores primos de N
int numPF(ll N) {
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)
        while (N%p[i] == 0) { N /= p[i]; ++ans; }
    return ans + (N != 1);
}

//Contar el numero de divisores de N
int numDiv(ll N) {
    int ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        int power = 0; // count the power
        while (N%p[i] == 0) { N /= p[i]; ++power; }
        ans *= power+1; // follow the formula
    }
    return (N != 1) ? 2*ans : ans; // last factor = N^1
}

//Suma de los divisores de N
ll sumDiv(ll N) {
    ll ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        ll multiplier = p[i], total = 1;
        while (N%p[i] == 0) {
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
    } // total for
    ans *= total; // this prime factor
    }
    if (N != 1) ans *= (N+1); // N^2-1/N-1 = N+1
    return ans;
}