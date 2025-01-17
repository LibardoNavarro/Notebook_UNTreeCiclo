int main() {
	ll n, capacidad;
	cin >> n >> capacidad;
	vl pesos(n, 0);
	forx(i, n) cin >> pesos[i];

	vector<pll> dp((1 << n));
	dp[0] = {1, 0};
	// dp[X] = {#numero de paquetes, peso de min paquete}

	// La idea es probar todos los subset y en cada uno preguntarnos
	// quien es mejor para subirse de ultimo buscando minimizar
	// primero el numero de paquetes
	for (int subset = 1; subset < (1 << n); subset++) {
		dp[subset] = {21, 0};

		for (int iPer = 0; iPer < n; iPer++) {
			if ((subset >> iPer) & 1) {
				pll ant = dp[subset ^ (1 << iPer)];
				ll k = ant.ff;
				ll w = ant.ss;

				if (w + pesos[iPer] > capacidad) {
					k++;
					w = min(pesos[iPer], w);
				} else {
					w += pesos[iPer];
				}

				dp[subset] = min(dp[subset], {k, w});
			}
		}
	}

	cout << dp[(1 << n) - 1].ff << ln;
}