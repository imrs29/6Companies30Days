//Bridge edge in a graph


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    void dfs(vector<int> adj[],vector<bool> &visited,int x,int p){
    visited[x]=true;          
    for(auto c:adj[x])
    
    {       
        if(!visited[c]){      
            if(c!=p)          
            dfs(adj,visited,c,x);
        }
    }
}
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V+1,false);
        
        if(find(adj[c].begin(),adj[c].end(),d)!=adj[c].end())                   
        adj[c].erase(find(adj[c].begin(),adj[c].end(),d));                     
        if(find(adj[d].begin(),adj[d].end(),c)!=adj[d].end())                 
        adj[d].erase(find(adj[d].begin(),adj[d].end(),c));                   
        dfs(adj,visited,d,-1);                                              
        return !visited[c]?1:0;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
