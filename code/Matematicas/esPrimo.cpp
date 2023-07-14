ll _sieve_size;
bitset<10000010> bs;
vl primos;
void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        primos.push_back(i);
    }
}
bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N]; // O(1)
    for (int i = 0; i < (int)primos.size() && primos[i]*primos[i] <= N; ++i)
        if (N%primos[i] == 0)
            return false;
    return true;
}
int main(){
    sieve(10000000);
}