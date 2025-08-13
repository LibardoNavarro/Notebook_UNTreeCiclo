// peso, nodo a, node b
vector<tuple<int,int,int>> edges;
struct DSU{};

// O(m*log(m))
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
