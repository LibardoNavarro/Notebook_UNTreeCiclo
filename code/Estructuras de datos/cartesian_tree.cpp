const int maxn = 1e6+5;
int l[maxn],r[maxn],a[maxn];

// 1-indexed, O(n)
int cartesian_tree(int n){ 
	int tot=0;
	vector<int> s(n+1,0);
	vector<bool> vis(n+1,false);
	for(int i=1;i<=n;++i)l[i]=r[i]=0;
	for(int i=1;i<=n;++i){
		int k=tot;
		while(k>0 && a[s[k-1]]>a[i])k--; // < max heap
		if(k)r[s[k-1]]=i;
		if(k<tot)l[i]=s[k];
		s[k++]=i;
		tot=k;
	}
	for(int i=1;i<=n;++i)vis[l[i]]=vis[r[i]]=1;
	int root=0;
	for(int i=1;i<=n;++i){
		if(!vis[i])root=i;
	}
	return root;
}