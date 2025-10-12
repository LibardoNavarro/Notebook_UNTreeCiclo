// A string is called simple if it is strictly smaller than all its nontrivial cyclic shifts.
// The Lyndon factorization of the string is s = w1 w2 ... wk
// where all strings wi are simple, and they are in non-increasing order
// w1 >= w2 >= ... >= wk
// this factorization exists and it is unique 

// O(n)
vector<string> duval(string& s){
	vector<string> factorization;
	int n=sz(s),i=0;
	while(i<n){
		int j=i+1,k=i;
		while(j<n && s[k]<=s[j]){
			if(s[k]<s[j])k=i;
			else k++;
			j++;
		}
		while(i<=k){
			factorization.push_back(s.substr(i, j-k));
			i+=j-k;
		}
	}
	return factorization;
}
