const int bits = 23;
int dp[1<<bits];

// O(n*2^n)
void SOS(){
	for(int i = 0; i < (1 << bits); ++i) dp[i] = A[i];

	// top - down (informacion de las submascaras)
	for(int i = 0; i < bits; ++i){
		for(int s = 0; s < (1 << bits); ++s){
			if(s & (1 << i)){
				dp[s] += dp[s ^ (1 << i)];
			}
		}
	} 
	
	// bottom - up (informacion de las supermascaras)
	for(int i = 0; i < bits; ++i){
		for(int s = (1 << bits) - 1; s >= 0; --s){
			if(s & (1 << i)){
				dp[s ^ (1 << i)] += dp[s];
			}
		}
	}
}


int dp2[1<<bits][bits+1];

// O(2^n*n^2)
void cnt(){
	vector<int> a;
	for(int x:a)dp2[x][0]++;

	// dp[s][c] = number of s^ai with c bits
	for(int i=0;i<bits;++i){
		for(int c=i;c>=0;--c){
			for(int s=0;s<(1<<bits);++s){
				dp2[s^(1<<i)][c+1]+=dp2[s][c];
			}
		}
	}
}