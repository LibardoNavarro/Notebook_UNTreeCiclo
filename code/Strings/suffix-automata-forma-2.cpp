// O(n) construccion, O(n) memoria
struct SuffixAutomaton {
  int last;
  vi len,link,firstPos;
  vl cnt;
  vector<array<int,2>> order;
  vector<array<int, ALPHA>> nxt;
  SuffixAutomaton():last(0),len(1),link(1,-1),firstPos(1),cnt(1),nxt(1){}
  SuffixAutomaton(const string &s):SuffixAutomaton(){
    for (char c:s)
      extend(c);
  }

  int getIndex(char c){
    return c-MIN_CHAR;
  }
 
  void extend(char c) {
    int act=sz(len), i=getIndex(c),p=last;
    len.push_back(len[last]+1);
    link.emplace_back();
    cnt.push_back(1);
    firstPos.emplace_back(len[last]+1);
    order.push_back({len[act],act});
    nxt.emplace_back();
    while(p != -1 && !nxt[p][i]){
      nxt[p][i]=act;
      p=link[p];
    }
    if(p!=-1){
      int q=nxt[p][i];
      if(len[p]+1==len[q]){
        link[act]=q;
      }else{
        int clone=sz(len);
        len.push_back(len[p]+1);
        link.push_back(link[q]);
        firstPos.push_back(firstPos[q]);
        cnt.push_back(0);
        order.push_back({len[clone],clone});
        nxt.push_back(nxt[q]);
        while(p!=-1 && nxt[p][i]==q){
          nxt[p][i]=clone;
          p=link[p];
        }
        link[q]=link[act]=clone;
      }
    }
    last=act;
  }
};
 
int main() {
SuffixAutomaton sa(string);
return 0;
}