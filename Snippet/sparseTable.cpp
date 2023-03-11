template <typename T>
struct SparseTable
{
    int n;
    int k;
    vector<vector<T>> st;
    vector<int> Log;
    void init(vector<T> &v)
    {
        n=v.size();
        k=(int)(log2(n))+1;

        st=vector<vector<T>>(n, vector<T>(k));
        Log=vector<int>(n+1);
        
        for(int j=0; j<k; j++)
        {
            for(int i=0; i+(1<<j)<=n; i++)
            {
                if(j==0)
                    st[i][j]=v[i];
                else 
                    st[i][j]=combine(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }
        Log[1]=0;
        for(int i=2; i<=n; i++)
        {
            Log[i]=Log[i/2]+1;
        }
    }

    T query(int l, int r)
    {
        int len=(r-l+1);
        int smallPower=Log[len];

        return combine(st[l][smallPower], st[r-(1<<smallPower)+1][smallPower]);
    }


    T combine(T a, T b)
    {
        return __gcd(a, b);
    }
};
