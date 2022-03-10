int longestCommonSubseqence (string a, string b, int n, int m)
    {
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            t[i][j]=0;
        }
        
        for(int i=0;i<n+1;i++)
        for(int j=0;j<m+1;j++)
        {
            if(a[i-1]==b[j-1])
            t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1])
        }
        return t[n][m];
    }
