vector<int> parent(205);
class Solution {
    
public:
    
    void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] =find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
    
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            make_set(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    union_sets(i,j);
                }
            }
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(find_set(i));
        }
        return s.size();
    }
};

//***********************************************************************

#include <bits/stdc++.h>
using namespace std;

vector<int> parent(500);

// int parent[200];
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        parent.clear();
        int n , m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        make_set(i);
        for(int i = 0  ; i < m ; i ++)
        {
            int u,v;
            cin>> u >> v;
            union_set(u,v);
        }
        set<int> s;
        for(int i=0;i<n;i++)
        s.insert(find_set(i));
        cout<<s.size()-1<<endl;
    }
    //code
    return 0;
}

// find edge which forms loop in a graph using union find method;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> parent(edges.size()+1,0);
        vector<int> ans;
        
        for(int i=0;i<parent.size();i++)
        parent[i]=i;
        
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            
            while(u!=parent[u])
                u = parent[u];
            while(v!=parent[v])
                v = parent[v];
            
            if(u==v)
                ans=e;
            else
                parent[v]=u;
        }
        return ans;
    }
