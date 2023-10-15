// La creacion del automata es O(n)
struct state {
  int len,link;
  map<char,int>next;
};

const int N=100000;
state st[N*2];
int sz,last;

void sa_init(){
  st[0].len=0;
  st[0].link=-1;
  sz++;
  last=0;
}

void sa_extend(char c){
  int act=sz++;
  st[act].len=st[last].len+1;
  int p=last;
  while(p!=-1 && !st[p].next.count(c)){
    st[p].next[c]=act;
    p=st[p].link;
  }
  if(p==-1){
    st[act].link=0;
  }else{
    int q=st[p].next[c];
    if(st[p].len+1==st[q].len){
      st[act].link=q;
    }else{
      int clone=sz++;
      st[clone].len=st[p].len+1;
      st[clone].next=st[q].next;
      st[clone].link=st[q].link;
      while(p!=-1 && st[p].next[c]==q){
        st[p].next[c]=clone;
        p=st[p].link;
      }
      st[q].link=st[act].link=clone;
    }
  }
  last=act;
}
