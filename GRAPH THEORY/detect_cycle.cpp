// kahn `s algorith for cycle detection in directed graph
    //      based on topological sort

        bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> in(V,0);
        for(int i=0;i<V;i++)
        for(auto x:adj[i])
        in[x]++;
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        if(in[i]==0)
        q.push(i);

        int ctr=0;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            for(auto x:adj[curr])
            {
            in[x]--;
            if(in[x]==0)
            q.push(x);
            }

            ctr++;
        }
        // if ctr is not equal to v then it returns false;
        return (ctr!=V);
        // code here
    }

// Function to detect cycle in an undirected graph.

    bool dfs(vector<int> adj[],vector<bool> &vis,int u,int par)
    {
        vis[u]=true;
        for(auto i: adj[u])
        {
            if(!vis[i])
            {
                bool c=dfs(adj,vis,i,u);
                if(c)
                return true;
            }
            else if(i!=par)
            return true;
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                bool c=dfs(adj,vis,i,-1);
                if(c==true)
                return true;
            }
        }
        return false;
        // Code here
    }

// **********************************************************************************************

// Function to detect cycle in a directed graph.

bool dfs(vector<int> adj[],vector<bool> &vis,vector<bool> &order,int u)
  {
      vis[u]=true;
      order[u]=true;
      for(auto i:adj[u])
      {
          if(!vis[i])
          {
          if(dfs(adj,vis,order,i))
          return true;
          }
          else if(order[i])
          return true;
      }
      order[u]=false;
      return false;
  }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> order(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
            if(dfs(adj,vis,order,i))
            return true;
            }
        }
        return false;
        // code here
    }
// ****************************************************************************************************************
// detect cycle in a directed graph

bool dfs(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr]==true)
        return true;
    
    visited[curr] = true;
  
    for(int i=0;i<adj[curr].size();++i)
    {
        FLAG = ;
        if(dfs(adj, visited, adj[curr][i]))
            return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
   vector<bool> visited(V,false);
   for(int i=0;i<V;++i)
   {
           visited[i] = true;
           for(int j=0;j<adj[i].size();++j)
           {
               if(dfs(adj,visited,adj[i][j]))
                   return true;
           }
           visited[i] = false;
   }
   return false;
}
