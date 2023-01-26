//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node,vector<int>&visited,vector<int>&dfsvisited,vector<int>adj[]){
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto nb:adj[node]){
            if(visited[nb] && dfsvisited[nb]){
                return 1;
            }
            else if(!visited[nb]){
                bool cyc=dfs(nb,visited,dfsvisited,adj);
                if(cyc) return 1;
            }
        }
        dfsvisited[node]=0;
        return 0;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int>visited(v,0);
        vector<int>dfsvisited(v,0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool cyc=dfs(i,visited,dfsvisited,adj);
                if(cyc) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends