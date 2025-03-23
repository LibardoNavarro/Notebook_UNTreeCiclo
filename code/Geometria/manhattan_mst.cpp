struct pt {
    ll x, y;
};

// Returns a list of edges in the format (weight, u, v). 
// Passing this list to Kruskal algorithm will give the Manhattan MST.
vector<tuple<ll, ll, ll>> manhattan_mst_edges(vector<pt> ps){
    vl ids(sz(ps));
	forx(i, sz(ps)) ids[i] = i;
    vector<tuple<ll, ll, ll>> edges;

    for (ll rot = 0; rot < 4; rot++) {
        
		sort(ids.begin(), ids.end(), [&](ll i, ll j){
            return (ps[i].x + ps[i].y) < (ps[j].x + ps[j].y);
        });

        map<ll, ll, greater<ll>> active; // (xs, id)
        for(auto i : ids){
            
			for(auto it = active.lower_bound(ps[i].x); it != active.end(); active.erase(it++)){
                ll j = it->second;
                if (ps[i].x - ps[i].y > ps[j].x - ps[j].y) break;
                assert(ps[i].x >= ps[j].x && ps[i].y >= ps[j].y);
                edges.push_back({(ps[i].x - ps[j].x) + (ps[i].y - ps[j].y), i, j});
            }

            active[ps[i].x] = i;
        }

        for (auto &p : ps){ // rotate
            if (rot & 1) p.x *= -1;
            else swap(p.x, p.y);
        }
    }

    return edges;
}