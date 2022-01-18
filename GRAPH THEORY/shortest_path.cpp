// Floyd warshall algo for all path shortest path

vector<vector<int>> dis(n, vector(n,10001));
       

        for(auto e:edges)
        {
            dis[e[0]][e[1]]=dis[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

// ***********************************************************************************************************
