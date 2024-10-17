struct node{
  int childs[2]{-1, -1};
};

struct TrieBit{
    vector<node> nds;
	vi passNums;
    
	TrieBit(){
        nds.pb(node());
        passNums.pb(0);
	}

    void insert(int num){
        int cur = 0;
        for(int i = 30; i >= 0; i--){
            bool bit = (num >> i) & 1;

            if(nds[cur].childs[bit] == -1){
                nds[cur].childs[bit] = nds.size();
                nds.pb(node());
                passNums.pb(0);
            }

            passNums[cur]++;
            cur = nds[cur].childs[bit];
        }

        passNums[cur]++;
    }

    void remove(int num){   
        int cur = 0;
        for(int i = 30; i >= 0; i--){
            bool bit = (num >> i) & 1;
            passNums[cur]--;
            cur = nds[cur].childs[bit];
        }

        passNums[cur]--;
    }

    int maxXor(int num){
        int ans = 0;
        int cur = 0;
        for(int i = 30; i >= 0; i--){
            bool bit = (num >> i) & 1;

            int n1 = nds[cur].childs[!bit]; 
            if (n1 != -1 && passNums[n1]){
                ans += (1 << i);
                bit = !bit;
            }

            cur = nds[cur].childs[bit];
        }

        return ans;
    }
};