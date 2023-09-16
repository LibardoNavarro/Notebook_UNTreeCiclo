#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string b1="hola",b2;int c1,c2;
while(cin>>b1, b1!="hola"){
  cin>>c1>>b2>>c2;
  
  if(b1==b2){
    if(c1==c2)cout<<"Draw\n";
    else if(c1>c2)cout<<"Tobby\n";
    else cout<<"Naebbirac\n";
  }

  else if(b1=="Battleships"){
    if(b2=="Destroyers"){
      if(c2>=c1*2)cout<<"Naebbirac\n";
      else cout<<"Tobby\n";
    }else{// cruisers b2
      if(c1>=c2*2)cout<<"Tobby\n";
      else cout<<"Naebbirac\n";
    }
  }

  else if(b1=="Cruisers"){
    if(b2=="Battleships"){
      if(c2>=c1*2)cout<<"Naebbirac\n";
      else cout<<"Tobby\n";
    }else{ //destroyers b2
      if(c1>=c2*2)cout<<"Tobby\n";
      else cout<<"Naebbirac\n";
    }
  }

  else{ //destroyers b1
    if(b2=="Cruisers"){
      if(c2>=c1*2)cout<<"Naebbirac\n";
      else cout<<"Tobby\n";
    }else{//Battleships b2
      if(c1>=c2*2)cout<<"Tobby\n";
      else cout<<"Naebbirac\n";
    }
  }

  b1="hola";
}return 0;}


















  // if(b1==b2){
  //   if(c1==c2)cout<<"Draw\n";
  //   else if(c1>c2)cout<<"Tobby\n";
  //   else cout<<"Naebbirac\n"; 
  // }


  // else if(b1=="Battleships"){
  //   if(b2=="Cruisers"){
  //     if(c2*2<=c1)cout<<"Tobby\n";
  //     else cout<<"Naebbirac\n";
  //   }else{//Destroyers
  //     if(c2>=2*c1)cout<<"Naebbirac\n";
  //     else cout<<"Tobby\n";
  //   }
  // }


  // else if(b1=="Cruisers"){
  //   if(b2=="Battleships"){
  //     if(c1*2<=c2)cout<<"Naebbirac\n";
  //     else cout<<"Tobby\n";
  //   }else{//Destroyers
  //     if(2*c2<=c1)cout<<"Tobby\n";
  //     else cout<<"Naebbirac\n";
  //   }
  // }



  // else{
  //   if(b2=="Battleships"){
  //     if(2*c2<=c1)cout<<"Tobby\n";
  //     else cout<<"Naebbirac\n";
  //   }else{ //Cruisers
  //     if(2*c2<=c1)cout<<"Tobby\n";
  //     else cout<<"Naebbirac\n";
  //   }
  // }
