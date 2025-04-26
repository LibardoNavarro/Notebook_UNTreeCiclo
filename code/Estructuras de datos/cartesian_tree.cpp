// O(n) build
typedef long long T;
struct CartesianTree{ // 1-indexed
	vector<int> l,r;
	int root,n;
	
	CartesianTree(vector<T>& a){
		reverse(all(a));
		a.push_back(0);
		reverse(all(a));
		int tot=0;n=sz(a)-1;
		l.assign(n+1,0);
		r.assign(n+1,0);
		vector<int> s(n+1,0);
		vector<bool> vis(n+1,false);
		for(int i=1;i<=n;++i){
			int k=tot;
			while(k>0 && a[s[k-1]]>a[i])k--; // < max heap
			if(k)r[s[k-1]]=i;
			if(k<tot)l[i]=s[k];
			s[k++]=i;
			tot=k;
		}
		for(int i=1;i<=n;++i)vis[l[i]]=vis[r[i]]=1;
		root=0;
		for(int i=1;i<=n;++i){
			if(!vis[i])root=i;
		}
	}
};