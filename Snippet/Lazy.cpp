//https://leetcode.com/problems/handling-sum-queries-after-update/description/
template <typename T>
struct segTree // 1-based indexing.
{
    int size, n;
    vector<T> st, lazy;
    int NO_OPERATION=LLONG_MAX-1;
    segTree(int sizeOfTree)
    {
        n = sizeOfTree;
        size = 1;
        while (size < sizeOfTree)
            size <<= 1;

        size <<= 1;
        st.resize(size + 1);
        lazy.assign(size + 1, 0);
    }

    void build(int si, int ss, int se, vector<T> &arr)
    {
        if (ss == se)
        {
            st[si] = arr[ss-1];
            return;
        }

        int mid = (ss + se) / 2;

        build(2 * si, ss, mid, arr);
        build(2 * si + 1, mid + 1, se, arr);

        st[si] = combine(st[2 * si], st[2 * si + 1]);
    }
    void propagate(int si, int ss, int se)  // Handle this function according to problem
    {
        if(lazy[si]==NO_OPERATION)
            return;

        if(ss==se) 
        {
            st[si]=1-st[si];
        }
        else
        {
            st[si]=(se-ss+1)-st[si];

            lazy[2*si]=1-lazy[2*si];
            lazy[2*si+1]=1-lazy[2*si+1];
        }

        lazy[si]=NO_OPERATION;
    }
    void modify(int si, int ss, int se, int l, int r)
    {
        propagate(si, ss, se);
        if (ss > r || se < l) return;

        if (l <= ss && r >= se)
        {
            lazy[si]=1;                 // Handle it according to problem
            propagate(si, ss, se);
            return;
        }

        int mid = (ss + se) / 2;

        modify(2 * si, ss, mid, l, r);
        modify(2 * si + 1, mid + 1, se, l, r);

        st[si]=combine(st[2*si], st[2*si+1]);
    }
    T query(int si, int ss, int se, int l, int r)
    {
        propagate(si, ss, se);
        if (ss > r || se < l)
            return 0;                   // Handle it according to problem

        if (l <= ss && r >= se)
            return st[si];

        int mid = (ss + se) / 2;

        T left = query(2 * si, ss, mid, l, r);
        T right = query(2 * si + 1, mid + 1, se, l, r);

        return combine(left, right);
    }

    T combine(T x, T y)                 // Handle it according to problem
    {
        return x+y;
    }

    void modify(int l, int r)
    {
        modify(1, 1, n, l, r);
    }

    T query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};

