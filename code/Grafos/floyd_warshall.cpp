// O(n^3)
vector<vi> adjMat(n+1, vi(n+1));
//Condicion previa: adjMat[i][j] contiene peso de la arista (i, j)
//o INF si no existe esa arista
for (int k = 0; k < n; ++k) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adjMat[i][k] < INF && adjMat[k][j] < INF)
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]); 
		}
	}
}