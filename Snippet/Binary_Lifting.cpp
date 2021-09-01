struct Binary_Lifting
{
    int N;
    int LOG;
    vt<vi> edge, up;
    vi depth;

    void init(int _n)
    {
        N = _n;
        LOG = log(N) + 3;

        edge.resize(N + 1);
        up.resize(N + 1);

        For(i, 0, N + 1)
            edge[i]
                .resize(0),
            up[i].assign(LOG, 0);
        depth.assign(N + 1, 0);
    }

    void dfs(int root, int par = 0)
    {
        for (int child : edge[root])
        {
            if (child != par)
            {
                depth[child] = depth[root] + 1;
                up[child][0] = root;
                for (int j = 1; j < LOG; j++)
                {
                    up[child][j] = up[up[child][j - 1]][j - 1];
                }
                dfs(child, root);
            }
        }
    }

    int LCA(int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        int k = depth[a] - depth[b];

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k & (1 << i))
                a = up[a][i];
        }

        if (a == b)
            return a;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[a][i] != up[b][i])
            {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }
};
