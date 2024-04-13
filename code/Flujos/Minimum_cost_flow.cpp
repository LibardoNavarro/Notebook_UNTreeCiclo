struct Edge{
    ll from, to, capacity, cost;
    Edge(ll from, ll to, ll capacity, ll cost) : from(from), to(to), capacity(capacity), cost(cost) {}
};

vector<vl> adj, cost, capacity;

void shortest_paths(int n, int v0, vl &d, vector<ll> &p) {
    d.assign(n, INFL);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<ll> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

ll min_cost_flow(int N, vector<Edge> &edges, ll K, int s, int t) {
    adj.assign(N, vl());
    cost.assign(N, vl(N, 0));
    capacity.assign(N, vl(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    ll flow = 0;
    ll cost = 0;
    vl d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INFL)
            break;

        // find max flow on that path
        ll f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    if (flow < K) return -1;
    else return cost;
}