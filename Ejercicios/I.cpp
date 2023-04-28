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

bool solve(long long n){
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
            return true;
        }else{
            return false;
        }
		
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	for (int i = 1;i <= pow(10, 10); i++){
        if (solve(i) != true){
            cout << "";
        }
        else{
            cout << i << ", ";
        }
	}
}
