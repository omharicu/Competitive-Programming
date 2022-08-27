template <typename T>
struct segTree // 1-based indexing.
{
    int size, n;
    vector<T> st, arr;

    segTree(int sizeOfTree)
    {
        n = sizeOfTree;
        arr.resize(n + 1);
        size = 1;
        while (size < sizeOfTree)
            size <<= 1;

        size <<= 1;
        st.resize(size + 1);
    }

    void set(int si, int ss, int se, int idx, T val)
    {
        if (ss == se)
        {
            st[si] = val;
            arr[idx] = val;
            return;
        }

        int mid = (ss + se) / 2;

        if (idx <= mid)
            set(2 * si, ss, mid, idx, val);
        else
            set(2 * si + 1, mid + 1, se, idx, val);

        st[si] = combine(st[2 * si], st[2 * si + 1]);
    }

    T query(int si, int ss, int se, int l, int r)
    {
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
        return x + y;
    }

    void set(int idx, T val)
    {
        set(1, 1, n, idx, val);
    }

    T query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};
