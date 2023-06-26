#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const char ln = '\n';


struct nodeSt{
    nodeSt *left,*right;
    ll l,r,val;

    nodeSt(vl &v,ll lef,ll rig): l(lef),r(rig){
        ll m = (l+r)/2;

        if (l != r){
            left = new nodeSt(v,lef,m);
            right = new nodeSt(v,m+1,rig);
            val = left->val+right->val; // cambio :U
        }else{
            val = v[l]; 
        }
    }

    ll get(ll i, ll j){
        if (l>=i && r<=j){
            return val;
        }
        if (l>j || r<i){
            return 0;
        }

        return left->get(i,j)+ right->get(i,j);
    }

    void actl(ll k, ll u){
        // u = val+u;
        if (l>k||r<k) return;
        if (l>=k && r<=k){
            val = val+u; // cambio
            return;
        }

        left->actl(k,u);
        right->actl(k,u);

        val = left->val+right->val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;cin>>n;

    vl vals(n);
    for(int i =0;i<n;i++) cin>>vals[i];
    nodeSt st(vals,0,n-1);

    
    int q;cin>>q;
    for(int i=0;i<q;i++){
        string s1;cin>>s1;
        ll n2,n3;cin>>n2>>n3;
        if (s1=="U"){
            n2--;
            st.actl(n2,n3);
        }else{
            n2--;n3--;
            cout<<st.get(n2,n3)<<ln;
        }
    }


}