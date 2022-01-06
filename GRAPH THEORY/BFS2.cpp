#include<bits/stdcpp.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int nv,e;
    cin>>nv>>e;
    vector<int> adj[nv];
    bool vis[nv]={false};
    for(int i=0;i<e;i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    bfs(0,adj,vis,ne);
    cout<<endl;
  }
}

void bfs(int s,vector<int> adj[],bool vis[],int nv)
{ 
  
	queue<int> queue;
	queue.push_back(s); 
  	vis[s]=true;
	while(!queue.empty()) 
	{
	   int curr = queue.front(); 
	   queue.pop_front(); 
   	   cout << curr << " ";
    
	   for (int i=0; i<adj[curr].size(); ++i) 
	   { 
		if(vis[adj[curr][i]]==false)
      		{
        	     queue.push_back(adj[curr][i]);
       		     vis[adj[curr][i]]=true;
      		}
	   }
	} 
} 
  
