//Algoritmo mas rapido de ruta minima
//O(V*E) peor caso, O(E) en promedio.
ll spfa(vector<vii>& adj, ll s, ll n) {
    vl d(n+1, INFL);
    vector<bool> inqueue(n, false);
    queue<ll> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                }
            }
        }
    }
    return d[n];
}