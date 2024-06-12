vi prefix_function(string s){
	int n=sz(s);
	vi pi(n);
	for(int i=1;i<n;i++) {
		int j=pi[i-1];
		while(j>0 && s[i]!=s[j])j=pi[j-1];
		if (s[i]==s[j])j++;
		pi[i]=j;
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;cin>>s;
	vi pi=prefix_function(s);
	for(int i=0;i<sz(s);i++)cout<<pi[i]<<" ";
	cout<<"\n";
	int n=sz(s);
	vi ans(n + 1);
	for(int i=0;i<n;i++)ans[pi[i]]++;
	for(int i=n-1;i>0;i--)ans[pi[i-1]]+=ans[i];
	for(int i=0;i<=n;i++)ans[i]++;
	for(int i=0;i<=n;i++)cout<<"El prefijo de tamaño "<<i<<" aparece "<<ans[i]<<" veces\n";
	return 0;
}