// Bipartite graph
// get return the leader and the parity of the distance to the leader
typedef pair<int, int> ii;
struct DSU{
	vector<int> p,size,len;
	DSU(int n){
		p.assign(n,0);
		len.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}
	ii get(int a){
		if(a==p[a])return {a, 0};
		ii va=get(p[a]);
		p[a]=va.first;
		len[a]=(len[a]+va.second)%2;
		return {p[a], len[a]};
	}
	void unite(int a, int b){
		ii va=get(a);
		ii vb=get(b);
		if(va.first==vb.first)return;
		if(size[va.first]>size[vb.first])swap(va,vb);
		p[va.first]=vb.first;
		len[va.first]=(va.second+vb.second+1)%2;
		size[vb.first]+=size[va.first];
	}
};
