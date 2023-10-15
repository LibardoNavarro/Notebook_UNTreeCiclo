int main() {
    //n: numero de grupo 1, m: numero de grupo 2, k: posibles conexiones
    int n, m, k; cin >> n >> m >> k;

    Dinic graph(n+m+2, 0, n+m+1);

    //nodo inicial ficticio "0" que se dirige a todos los del grupo 1
    for (int i = 1; i<=n; i++) graph.add_edge(0, i, 1LL);

    //nodo final ficticio "n+m+1" al que se dirigen todos los del grupo 2
    for (int i = 1; i<=m; i++) graph.add_edge(n+i, n+m+1, 1LL);

    //anadiendo las posibles conexiones al grafo
    for (int i = 0; i<k; i++){
        int a, b; cin >> a >> b;
        graph.add_edge(a, n+b, 1LL);
    }

    //numero de emparejamientos realizados
    cout << graph.flow() << ln;

    //emparejamientos realizados
    for (FlowEdge edge : graph.edges){
        if (edge.v != 0 && edge.u != n+m+1 && edge.flow > 0){
            cout << edge.v << " " << edge.u - n << ln;
        }
    }

    return 0;
}