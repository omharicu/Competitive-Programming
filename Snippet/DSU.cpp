struct DSU
{
    vector<int> Parent, Size;
    void dsu_init(int size)
    {
        Parent.resize(size+2);
        Size.resize(size+2);

        for (int i = 0; i < size+2; i++)
            Parent[i]=i, Size[i]=1;
    }

    int dsu_find(int v)
    {
        if(v==Parent[v])
            return v;
        return Parent[v]=dsu_find(Parent[v]);
    }

    void dsu_union(int a, int b)
    {
        a=dsu_find(a);
        b=dsu_find(b);

        if(a!=b)
        {
            if(Size[a]<Size[b])
                swap(a, b);

            Parent[b]=a;
            Size[a]+=Size[b];
        }
    }

};
