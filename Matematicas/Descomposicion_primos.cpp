#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

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
    vl r;
    r = primeFactors((1LL<<31)-1);
    for (auto &pf : r) cout << "> " << pf << "\n";
    cout << "\n";
    r = primeFactors(136117223861LL);
    for (auto &pf : r) cout << "> " << pf << "\n";
    cout << "\n";
    r = primeFactors(5000000035LL);
    for (auto &pf : r) cout << "> " << pf << "\n";
    cout << "\n";
    r = primeFactors(142391208960LL);
    for (auto &pf : r) cout << "> " << pf << "\n";
    cout << "\n";
    r = primeFactors(100000380000361LL);
    for (auto &pf : r) cout << "> " << pf << "\n";
}

//Variantes del algoritmo

//Contar el número de factores primos de N
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

//EulerPhi(N): contar el número de enteros positivos < N que son primos relativos a N.
ll EulerPhi(ll N) {
    ll ans = N; // start from ans = N
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        if (N%p[i] == 0) ans -= ans/p[i]; // count unique
        while (N%p[i] == 0) N /= p[i]; // prime factor
    }
    if (N != 1) ans -= ans/N; // last factor
    return ans;
}

//Criba modificada
/*
Si hay que determinar el numero de factores primos para muchos (o un rango) de enteros.
La mejor solucion es el algoritmo de criba modificada O(N log log N)
*/
int numDiffPFarr[MAX_N+10] = {0}; // e.g., MAX_N = 10^7
for (int i = 2; i <= MAX_N; ++i)
    if (numDiffPFarr[i] == 0) // i is a prime number
        for (int j = i; j <= MAX_N; j += i)
            ++numDiffPFarr[j]; // j is a multiple of i

//Similar para EulerPhi
int EulerPhi[MAX_N+10];
for (int i = 1; i <= MAX_N; ++i) EulerPhi[i] = i;
for (int i = 2; i <= MAX_N; ++i)
    if (EulerPhi[i] == i) // i is a prime number
        for (int j = i; j <= MAX_N; j += i)
            EulerPhi[j] = (EulerPhi[j]/i) * (i-1);