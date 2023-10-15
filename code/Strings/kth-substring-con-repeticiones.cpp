// Implementar primero suffix-automata-forma-2 y meter la funcion dentro
// El k-esimo substring lexicografico con repeticiones O(n+m)
void kthSubstr(ll k){
  sort(order.rbegin(), order.rend());
  for(auto [_,u]:order) {
    cnt[link[u]]+=cnt[u];
  }
  vl dp(last+1);
  function<void(int)>dfs=[&](int u){
    dp[u]=cnt[u];
    for(int i=0;i<26;i++){
      if(!nxt[u][i])continue;
      int v=nxt[u][i];
      if (!dp[v])dfs(v);
      dp[u]+=dp[v]; 
    }
  };
  dfs(0);
  int u=0;
  while(k>0){
    for(int i=0;i<26;i++) {
      if(!nxt[u][i])continue;
      int v=nxt[u][i];
      if(k>dp[v]) {
        k-=dp[v];
      }else{
        cout<<(char)('a' + i);
        k-=cnt[v];
        u=v;
        break;
      }
    }
  }
}
