// shortestpath path using topoSort
//     For a general weighted graph, we can calculate single source shortest distances in O(VE) time using Bellman–Ford Algorithm. 
//         For a graph with no negative weights, we can do better and calculate single source shortest distances in O(E + VLogV) time using Dijkstra’s algorithm. 
//             Can we do even better for Directed Acyclic Graph (DAG)? We can calculate single source shortest distances in O(V+E) time for DAGs. 
//                 The idea is to use Topological Sorting.

// We initialize distances to all vertices as infinite and distance to source as 0,
// then we find a topological sorting of the graph. Topological Sorting of a graph represents a linear ordering of the graph



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

// topological sort only for DAG
// lower degree comes first then higher

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
