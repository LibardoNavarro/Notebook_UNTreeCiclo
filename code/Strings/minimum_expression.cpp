// O(n)
int minimum_expression(string s){
	s=s+s;int n=sz(s),i=0,j=1,k=0;
	while(i+k<n && j+k<n){
		if(s[i+k]==s[j+k])k++;
		else if(s[i+k]>s[j+k])i=i+k+1,k=0; // < max
		else j=j+k+1,k=0;
		if(i==j)j++;
	}
	return min(i, j);
}
