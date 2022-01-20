class Solution {
public:
    bool bipartitebfs(vector<vector<int>> &graph,vector<int> &color,int u)
    {
        queue<int> q;
        q.push(u);
        color[u]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto i:graph[curr])
            {
                if(color[i]==-1)
                {
                    color[i]=1-color[curr];
                    q.push(i);
                }
                else if(color[i]==color[curr])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
            if(color[i]==-1)
            {
                if(!bipartitebfs(graph,color,i))
                    return false;
            }
        return true;
        
    }
};
