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

// Dijkastra algor for single source shortest path to all vertices

void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
    dist[src] = 0;
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push({0,src});
    
  
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
  
        // 'i' is used to get all adjacent vertices of a vertex
        
        for(auto i:adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i.first;
            int weight = i.second;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
// **********************************************************************************************************************************
