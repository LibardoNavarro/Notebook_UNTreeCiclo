// O(nlogn)
struct SuffixArray{
	const int alpha = 256;
	string s;int n;
	vi sa,rnk,lcp;

	void build(string& _s){
		s=_s;s.push_back('$'); // check
		n=sz(s);
		sa.assign(n, 0);
		rnk.assign(n, 0);
		lcp.assign(n-1, 0);
		buildSA();
	}

	void buildSA() {
		vi cnt(max(alpha, n),0);
		for(int i=0;i<n;++i)cnt[s[i]]++;
		for(int i=1;i<max(alpha,n);++i)cnt[i]+=cnt[i-1];
		for(int i=n-1;i>=0;--i)sa[--cnt[s[i]]]=i;
		for(int i=1;i<n;++i)rnk[sa[i]]=rnk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);

		for(int k=1;k<n;k*=2){
			vi nsa(n),nrnk(n),ncnt(n);
			for(int i=0;i<n;++i)sa[i]=(sa[i]-k+n)%n;
			for(int i=0;i<n;++i)ncnt[rnk[i]]++;
			for(int i=1;i<n;++i)ncnt[i]+=ncnt[i-1];
			for(int i=n-1;i>=0;--i)nsa[--ncnt[rnk[sa[i]]]]=sa[i];
			for(int i=1;i<n;++i){
				ii op1={rnk[nsa[i]], rnk[(nsa[i]+k)%n]};
				ii op2={rnk[nsa[i-1]], rnk[(nsa[i-1]+k)%n]};
				nrnk[nsa[i]]=nrnk[nsa[i-1]]+(op1!=op2);
			}
			swap(sa, nsa);swap(rnk, nrnk);
		}

		for(int i=0,k=0;i<n-1;++i){
			while(s[i+k]==s[sa[rnk[i]-1]+k])k++;
			lcp[rnk[i]-1]=k;
			if(k)k--;
		}
	}
};