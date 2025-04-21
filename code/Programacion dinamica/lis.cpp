// O(n*log(n))
// retorna los indices de un lis
// cambiar el tipo y revisar si permite iguales
typedef int T;
vector<int> lis(vector<T>& a, bool equal){
	vector<int> prev(sz(a));
	typedef pair<T, int> p;
	vector<p> res;
	for(int i=0;i<sz(a);++i){
		auto it=lower_bound(all(res), p{a[i],(equal?i:0)});
		if(it==res.end())res.emplace_back(),it=res.end()-1;
		*it={a[i],i};
		prev[i]=(it==res.begin())?0:(it-1)->second;
	}
	int l=sz(res),act=res.back().second;
	vector<int> ans(l);
	while(l--)ans[l]=act,act=prev[act];
	return ans;
}
