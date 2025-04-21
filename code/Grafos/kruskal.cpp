vector<tuple<int,int,int>> edges;
// peso, nodo a, node b

struct DSU{
	int sets;
	DSU(int n){}
	int get(int a);
	void unite(int a, int b);
};
 
// O(m*log(n))
void kruskal(int n){
	sort(all(edges));
	DSU dsu(n);
	ll ans=0;
	for(auto& [w,u,v]:edges){
		if(dsu.get(u)!=dsu.get(v)){
			dsu.unite(u, v);
			ans+=w;
		}
	}
	if(dsu.sets!=1)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<"\n";
}
