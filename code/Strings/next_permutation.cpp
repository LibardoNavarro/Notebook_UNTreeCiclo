// O(n)
// 1) find the last i such that ai<ai+1
// 2) find the last j such that ai<aj
// 3) swap i and j, then reverse the segment [i+1, n-1]
string nextPermutation(string& s){ 
	string ans(s);
	int n=sz(s);
	int i=n-2;
	while(i>=0 && ans[i]>=ans[i+1])i--;
	if(i<0)return "no permutation";
	int j=n-1;
	while(ans[i]>=ans[j])j--;
	swap(ans[i], ans[j]);
	int l=i+1,r=n-1;
	while(r>l)swap(ans[r--], ans[l++]);
	return ans;
}
