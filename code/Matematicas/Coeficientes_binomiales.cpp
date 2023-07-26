const int MAX_N = 100010;

ll inv (ll a){
    return binpow(a, MOD-2, MOD);
}

ll fact[MAX_N];
ll C(int n, int k){
    if (n < k) return 0;
    return (((fact[n] * inv(fact[k])) % MOD) * inv(fact[n-k])) % MOD;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i<MAX_N; i++){
        fact[i] = (fact[i-1]*i) % MOD;
    }
    cout << C(100000, 50000) << "\n";

    return 0;
}