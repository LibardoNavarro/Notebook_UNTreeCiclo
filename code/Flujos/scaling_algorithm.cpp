// O(|E|^2*log(C)) C = maximum edge weight of the graph
struct MaxFlow {
    static const ll INF = 1e18;
    struct Edge {int u,v;ll w;};
    int n, s, t;
    vector<vector<int>> g;
    vector<Edge> ed;
    vector<bool> vis;
    ll flow = 0;
    MaxFlow(int n, int s, int t) : n(n), s(s), t(t), g(n) {}
    int add_edge(int u, int v, ll forward, ll backward = 0) {
        const int id = (int)ed.size();
        g[u].emplace_back(id);
        ed.push_back({u, v, forward});
        g[v].emplace_back(id + 1);
        ed.push_back({v, u, backward});
        return id;
    }
    bool dfs(int node, ll lim) {
        if (node == t) return true;
        if (vis[node]) return false;
        vis[node] = true;
        for (int i : g[node]) {
            auto &e = ed[i];
            auto &back = ed[i ^ 1];
            if (e.w >= lim) {
                if (dfs(e.v, lim)) {
                    e.w -= lim;
                    back.w += lim;
                    return true;
                }
            }
        }
        return false;
    }
    ll max_flow() {
        for (ll bit = 1ll << 62; bit > 0; bit /= 2) {
            bool found = false;
            do {
                vis.assign(n, false);
                found = dfs(s, bit);
                flow += bit * found;
            } while (found);
        }
        return flow;
    }
};