// shortestpath path using topoSort
    
    vector<int> shortestpath(int V,vector<int> adj[],int source)
    {
        vector<int> dis(V,INT_MAX);
        dist[source]=0;
        vector<int> order=topoSort(V,adj);
        for(auto u:order)
        {
            for(auto v:adj[u])
                if(dis[v]>dis[u]+weight[u,v])
                    dis[v]=dis[u]+ weight[u,v];
        }
        return dis;// distace to any vertex from source
    }

// *************************************************************************************

// topological sort

    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> in(V,0);
        for(int i=0;i<V;i++)
        for(auto x:adj[i])
        in[x]++;
        
        queue<int> q;
        vector<int> ans;
        
        for(int i=0;i<V;i++)
        if(in[i]==0)
        q.push(i);
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto x:adj[curr])
            {
            in[x]--;
            if(in[x]==0)
            q.push(x);
            }
        }
        
        return ans;
        // code here
    }
