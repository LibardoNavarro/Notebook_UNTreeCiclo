//Arbol de minima expansion
//O(E*log V)
vector<tuple<int,int,int>> edges;
void kruskal(){
	ll ans=0;
	dsu uf(n);
	sort(all(edges));
	for(auto& [w,u,v]:edges){
		if(uf.get(u)!=uf.get(v)){
			uf.unite(u, v);
			ans+=w;
		}
	}
	if(uf.sets==1){
		cout<<ans<<"\n";
	}
}