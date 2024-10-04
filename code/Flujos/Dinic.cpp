// O(|E|*|V|^2)
struct edge { ll v, cap, inv, flow; };
struct network {
  ll n, s, t;
  vector<ll> lvl;
  vector<vector<edge>> g;
  network(ll n) : n(n), lvl(n), g(n) {}
  void add_edge(int u, int v, ll c) {
    g[u].push_back({v, c, g[v].size(), 0});
    g[v].push_back({u, 0, g[u].size()-1, c});
  }
  bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<ll> q;
    lvl[s] = 0;
    for(q.push(s); q.size(); q.pop()) {
      ll u = q.front();
      for(auto &e : g[u]) {
        if(e.cap > 0 && lvl[e.v] == -1) {
          lvl[e.v] = lvl[u]+1;
          q.push(e.v);
        }
      }
    }
    return lvl[t] != -1;
  }
 
  void min_cut(){
    queue<ll> q;
    vector<bool> vis(n, 0);
    vis[s] = 1;
    for(q.push(s); q.size(); q.pop()) {
      ll u = q.front();
      for(auto &e : g[u]) {
        if(e.cap > 0 && !vis[e.v]) {
          q.push(e.v);
          vis[e.v] = 1;
        }
      }
    }
    set<ii> ans;
    for (int i = 0; i<n; i++){
        for (auto &e : g[i]){
            if (vis[i] && !vis[e.v]){
                ans.insert({i+1, e.v+1});
            }
        }
    }
    for (auto [x, y] : ans) cout << x << ' ' << y << ln;
  }
  ll dfs(ll u, ll nf) {
    if(u == t) return nf;
    ll res = 0;
    for(auto &e : g[u]) {
      if(e.cap > 0 && lvl[e.v] == lvl[u]+1) {
        ll tf = dfs(e.v, min(nf, e.cap));
        res += tf; nf -= tf; e.cap -= tf;
        g[e.v][e.inv].cap += tf;
        g[e.v][e.inv].flow -= tf;
        e.flow += tf;
        if(nf == 0) return res;
      }
    }
    if(!res) lvl[u] = -1;
    return res;
  }
  ll max_flow(ll so, ll si, ll res = 0) {
    s = so; t = si;
    while(bfs()) res += dfs(s, LONG_LONG_MAX);
    return res;
  }
};