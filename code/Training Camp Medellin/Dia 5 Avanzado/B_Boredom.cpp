#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const char ln = '\n';

ll recur(ll indi,vl& vals,ll can,vl& memo){
    if (memo[indi]!=-1){
        return memo[indi];
    }
    if (indi>=can){
        return vals[indi]*indi;
    }
    ll op1 = (vals[indi]*indi)+recur(indi+2,vals,can,memo);
    ll op2 = (vals[indi+1]*(indi+1))+recur(indi+3,vals,can,memo);
    memo[indi]=max(op1,op2);
    return max(op1,op2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n1;cin>>n1;
    vl reps(10e5,0);
    ll mini=LONG_LONG_MAX;
    ll maxi=LONG_LONG_MIN;
    for (int i=0;i<n1;i++){
        ll indi;cin>>indi;
        mini = min(mini,indi);
        maxi = max(maxi,indi);
        reps[indi]+=1;
    }
    
    // ll cant=0;
    // for (ll punt:reps){
    //     if (punt!=0){
    //         cant++;
    //     }
    // }

    vl memo(10e5,-1);
    cout<<recur(mini,reps,maxi,memo)<<ln;
    
}