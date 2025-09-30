// los k numeros mas frecuentes
// el cero es un valor neutral dentro del vector
// no usarlo en el array original (a[i] > 0, i e [0,n-1])
// el vector guarda {valor, contador}
// pero contador es para el algo, no es la cantidad real

// algoritmo de misra-gries O(k^2)
vector<ii> null(k, {0,0});
vector<ii> init(int v){
	vector<ii> a=null;
	a[0]={v,1};
	return a;
}
vector<ii> oper(vector<ii> a, vector<ii> b, int k) {
	for (int i = 0; i < k; ++i) if (b[i].first) {
		int p = -1, q = -1;
		for (int j = 0; j < k; ++j) {
			if (b[i].first == a[j].first) p = j;
			if (!a[j].first) q = j;
		}
		if (p != -1) {
			a[p].second += b[i].second;
		} else if (q != -1) {
			a[q] = b[i];
		} else {
			int mn = b[i].second;
			for (int j = 0; j < k; ++j) mn = min(mn, a[j].second);
			for (int j = 0; j < k; ++j) a[j].second -= mn;
			b[i].second -= mn;
			for (int j = 0; j < k; ++j) if (!a[j].second) {
				if (b[i].second > 0) {
					a[j] = b[i], b[i].second = 0;
				} else {
					a[j].first = 0;
				}
			}
		}
	}
	return a;
}
