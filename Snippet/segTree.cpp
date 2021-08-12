struct segTree 
{                       //1-based indexing.
    int size, n;
    vector<int> st, arr;

    void init(int sizeOfTree)
    {
        n=sizeOfTree;
        arr.resize(n+1);
        size=1;
        while(size<sizeOfTree) size<<=1;

        size<<=1;
        st.assign(size+1, 0LL);
    }

    void set(int si, int ss, int se, int idx, int val)
    {
        if(ss==se)
        {
            st[si]=val;
            arr[idx]=val;
            return;
        }

        int mid=(ss+se)/2;

        if(idx<=mid)
            set(2*si, ss, mid, idx, val);
        else 
            set(2*si+1, mid+1, se, idx, val);

        st[si]=st[2*si]+st[2*si+1];
    }

    int query(int si, int ss, int se, int l, int r)
    {
        if(ss>r || se<l)
            return 0;

        if(l<=ss && r>=se)
            return st[si];    

        int mid=(ss+se)/2;

        int sumLeft=query(2*si, ss, mid, l, r);
        int sumRight=query(2*si+1, mid+1, se, l, r);

        return sumLeft+sumRight;
    }

    void set(int idx, int val)
    {
        set(1, 1, n, idx, val);
    }

    int query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};
