void dfs(vector<vector<int>> &g,vector<bool> &vis,int &u)
    {
        vis[u]=true;
        for(auto i:g[u])
        {
            if(!vis[i])
                dfs(g,vis,i);
                
        }
    }
