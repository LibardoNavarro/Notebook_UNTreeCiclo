int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin >> n;
    vl vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    vl copia(vals);
    sort(copia.begin(),copia.end());

    map <ll,ll> dicc;
    for (int i=0;i<n;i++)if (!dicc.count(copia[i])) dicc[copia[i]]=i;

    vl baseSt(n,0);
    nodeSt st(baseSt, 0, n - 1);
    ll maxi =0;
    for (ll pVal:vals) {
        ll op =st.get(0,dicc[pVal]-1)+1;
        maxi = max(maxi,op);
        st.actl(dicc[pVal],op);
    }
    cout<<maxi<<ln;
}