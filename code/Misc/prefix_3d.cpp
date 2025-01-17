const int N = 100;
int A[N][N][N];
int preffix[N + 1][N + 1][N + 1];

void build(int n){
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			for (int z = 1; z <= n; z++){
				preffix[x][y][z] = A[x - 1][y - 1][z - 1]
					+ preffix[x - 1][y][z] + preffix[x][y - 1][z] + preffix[x][y][z - 1]
					- preffix[x - 1][y - 1][z] - preffix[x - 1][y][z - 1] - preffix[x][y - 1][z - 1]
					+ preffix[x - 1][y - 1][z - 1];
			}

		}

	}
}

ll query(int lx, int rx, int ly, int ry, int lz, int rz){
	ll ans = preffix[rx][ry][rz] 
		- preffix[lx - 1][ry][rz] - preffix[rx][ly - 1][rz] - preffix[rx][ry][lz - 1]
		+ preffix[lx - 1][ly - 1][rz] + preffix[lx - 1][ry][lz - 1] + preffix[rx][ly - 1][lz - 1]
		- preffix[lx - 1][ly - 1][lz - 1];
	
	return ans;
}


