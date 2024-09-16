struct dsu{
    vi p,size;
    int sets,maxSize;

    dsu(int n){
        p.assign(n,0);
        size.assign(n,1);
        sets = n;
        for (int i = 0; i<n; i++) p[i] = i;
    }

    int find_set(int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

    bool is_same_set(int i, int j) {return find_set(i) == find_set(j);}

    void unionSet(int i, int j){
            if (!is_same_set(i, j)){
                int a = find_set(i), b = find_set(j);
                if (size[a] < size[b])
                    swap(a, b);
                p[b] = a;
                size[a] += size[b];
                maxSize = max(size[a], maxSize);
                sets--;
            }
        }
};