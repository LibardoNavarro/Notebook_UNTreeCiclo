typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());
u64 hash=rng();

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b){return uniform_int_distribution<int>(a, b)(rng);} // uniform_real_distribution
