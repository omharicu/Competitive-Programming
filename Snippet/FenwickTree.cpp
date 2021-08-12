struct FenwickTree
{
    int N;
    vector<int> BIT; // binary indexed tree(1-based)

    void init(int n)
    {
        N = n;
        BIT.assign(n + 1, 0);
    }

    int sum(int idx)
    {
        int ret = 0;
        while (idx > 0)
        {
            ret += BIT[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }

    int rsum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int val)
    {
        while (idx <= N)
        {
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }

    void r_updt(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    //It can handle one of following
        //1.) Point Update and Range Query
        //2.) Range Update and Point Query
};
