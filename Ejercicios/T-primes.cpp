#include <bits/stdc++.h>
using namespace std;
 
bool binary_search(double n){
    long long izq = 1;
    long long der = ((long long)n)-1;
    while (izq <= der){
        long long mid = (izq+der)/2;
        double mid1 = (double) mid;
        double mid2 = mid1 * mid1;
        if (mid2 == n){
            return true;
        }
        else if((mid2) < n){
            izq = mid + 1;
        }
        else{
            der = mid -1;
        }
    }
    return false;
}
 
string solve(long long n){
		int a = 0;
		for (long long i = 1; i<floor(pow(n, 0.5)); i++){
			if (n % i == 0){
				a += 2;
			}
		}
        if (binary_search((double)n) == true){
            a++;
        }
        if (a == 3){
            return "YES";
        }else{
            return "NO";
        }	
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	long long t; cin >> t;
    vector<long long> v(t);
    for (long long i = 0; i < t; i++){
        long long x; cin >> x;
        v[i] = x;
    }
	for (long long i = 0; i < t; i++){
        
		cout << solve(v[i]) << "\n";
 
	}
}