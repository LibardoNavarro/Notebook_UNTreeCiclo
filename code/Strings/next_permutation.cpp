// O(n)
string nextPermutation(string& s){ 
	string ans(s);
	int n=sz(s);
	int j=n-2;
	while(j>=0 && ans[j]>=ans[j+1])j--;
	if(j<0)return "no permutation";
	int k=n-1;
	while(ans[j]>=ans[k])k--;
	swap(ans[j], ans[k]);
	int r=n-1,l=j+1;
	while(r>l)swap(ans[r--], ans[l++]);
	return ans;
}
