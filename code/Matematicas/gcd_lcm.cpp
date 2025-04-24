//O(log10 n) n == max(a, b)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
//gcd(a, b, c) = gcd(a, gcd(b, c))
//gcd(a, b) = gcd(a, b-a)

// O(log(min(a, b)) - a*x+b*y=gcd(a,b)
ll gcd(ll a, ll b, ll &x, ll &y){
	x=1,y=0;
	ll x1=0,y1=1,a1=a,b1=b;
	while(b1){
		ll q=a1/b1;
		tie(x, x1)=make_tuple(x1, x-q*x1);
		tie(y, y1)=make_tuple(y1, y-q*y1);
		tie(a1, b1)=make_tuple(b1, a1-q*b1);
	}return a1;
}
