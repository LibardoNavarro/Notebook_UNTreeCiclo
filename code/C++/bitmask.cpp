* Operaciones a nivel de bits. Si n es ll usar 1ll<< en los corrimientos.

x & 1           -> Verifica si x es impar
x & (1<<i)      -> Verifica si el i-esimo bit esta encendido
x = x | (1<<i)  -> Enciende el i-esimo bit
x = x & ~(1<<i) -> Apaga el i-esimo bit
x = x ^ (1<<i)  -> Invierte el i-esimo bit
x = ~x          -> Invierte todos los bits
x & -x          -> Devuelve el bit encendido mas a la derecha (potencia de 2, no el indice)
~x & (x+1)      -> Devuelve el bit apagado mas a la derecha (potencia de 2, no el indice)
x = x | (x+1)   -> Enciende el bit apagado mas a la derecha
x = x & (x-1)   -> Apaga el bit encendido mas a la derecha
x = x & ~y      -> Apaga en x los bits encendidos de y

* Funciones del compilador gcc. Si n es ll agregar el sufijo ll, por ej: __builtin_clzll(n).

__builtin_clz(x)      -> Cantidad de bits apagados por la izquierda
__builtin_ctz(x)      -> Cantidad de bits apagados por la derecha. Indice del bit encendido mas a la derecha
__builtin_popcount(x) -> Cantida de bits encendidos
__builtin_ffs(x)	  -> Posicion del primer bit prendido (lsb+1)

* Logaritmo en base 2 (entero). Indice del bit encendido mas a la izquierda. Si x es ll usar 63 y clzll(x).
// O(1)
int lg2(const int &x) { return 31-__builtin_clz(x); }

* Itera, con indices, los bits encendidos de una mascara.
// O(#bits_encendidos)
for (int x = mask; x; x &= x-1) {
	int i = __builtin_ctz(x);
}

* Itera todas las submascaras de una mascara. (Iterar todas las submascaras de todas las mascaras es O(3^n)).
// O(2^(#bits_encendidos))
for (int sub = mask; ; sub = (sub-1)&mask) {
	// ... 
	if (sub == 0) break;
}

// Ascendente
for(int sub = 0; ; sub = (sub-mask)&mask) { 
	// ...
	if (sub == mask) break;
}

* retorna la siguiente mask con la misma cantidad encendida
ll nextMask(ll x){
	ll c = x & -x;
	ll r = x + c;
	return (((r ^ x) >> 2) / c) | r;
}

// optimiza el .count de los bitsets y el popcount
#pragma GCC target("popcnt")

// Formulas
a | b = a ^ b + a & b 
a ^ (a & b) = (a | b) ^ b
b ^ (a & b) = (a | b) ^ a
(a & b) ^ (a | b) = a ^ b
a + b = a | b + a & b
a + b = a ^ b + 2 * (a & b)
a - b = (a ^ (a & b)) - ((a | b) ^ a)
a - b = ((a | b) ^ b) - ((a | b) ^ a)
a - b = (a ^ (a & b)) - (b ^ (a & b))
a - b = ((a | b) ^ b) - (b ^ (a & b))
a ^ b = ~(a & b) & (a | b)
si (x < y < z) entonces min(x^y, y^z) < (x^z)