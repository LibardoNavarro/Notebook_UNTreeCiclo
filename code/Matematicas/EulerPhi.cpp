//EulerPhi(N): contar el numero de enteros positivos < N que son primos relativos a N.
//El vector p es el que genera la criba de eratostenes
//Phi(N) = N * productoria(1 - (1/pi))
ll EulerPhi(ll N) {
    ll ans = N; // Empezar con ans = N
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        if (N%p[i] == 0) ans -= ans/p[i]; //contar factores
        while (N%p[i] == 0) N /= p[i];    //primos unicos
    }
    if (N != 1) ans -= ans/N; // ultimo factor
    return ans;
}