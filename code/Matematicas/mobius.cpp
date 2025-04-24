// 1 if n is 1
// 0 if n has a squared prime factor
// (-1)^k if n is a product of k distinct prime factors
const int N = 1e6+1; 
int mob[N];
void mobius() {
	mob[1] = 1;
	for (int i = 2; i < N; i++){
		mob[i]--;
		for (int j = i + i; j < N; j += i) {
			mob[j] -= mob[i];
		}
	}
}

// to count coprime pairs
// ans=n*(n-1)/2
// for(int x:a){
// 		for(int y:divisors[a])cnt[y]++;
// }
// ans+=(mobius[v]*cnt[v]*(cnt[v]-1))/2
