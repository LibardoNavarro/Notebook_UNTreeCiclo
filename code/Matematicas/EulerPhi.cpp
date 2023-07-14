//EulerPhi(N): contar el numero de enteros positivos < N que son primos relativos a N.
//El vector p es el que genera la criba de eratostenes
ll EulerPhi(ll N) {
    ll ans = N; // start from ans = N
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        if (N%p[i] == 0) ans -= ans/p[i]; // count unique
        while (N%p[i] == 0) N /= p[i]; // prime factor
    }
    if (N != 1) ans -= ans/N; // last factor
    return ans;
}