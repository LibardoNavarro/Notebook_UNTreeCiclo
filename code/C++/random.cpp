typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());
u64 xor_hash=rng();

// return random numbers in the range [l,r]
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
double rand(double l, double r){return uniform_real_distribution<double>(l, r)(rng);} 
int rand(int l, int r){return uniform_int_distribution<int>(l, r)(rng);} 
