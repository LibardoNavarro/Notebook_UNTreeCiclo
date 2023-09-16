#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string st;
while(getline(cin, st) && st!=""){
  st.erase(remove(st.begin(), st.end(), ' '), st.end());
  int lon=st.length();
  bool par=false,impar=false;
  for(int i=1;i<lon-1;i++){
    if(st[i]==st[i-1] || st[i]==st[i+1])par=true;
    if(st[i-1]==st[i+1])impar=true;
  }
  if(lon==2 && st[0]==st[1])par=true;
  if(par && impar)cout<<"Both\n";
  else if(impar)cout<<"Odd\n";
  else if(par)cout<<"Even\n";
  else cout<<"None\n";
}
return 0;
}