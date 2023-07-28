ll Cat[MAX_N];

int main() {
    Cat[0] = 1;
    for (int n = 0; n < MAX_N-1; n++){
        Cat[n+1] = ((4*n+2)%MOD * Cat[n]%MOD * inv(n+2)) % MOD;
    }
}