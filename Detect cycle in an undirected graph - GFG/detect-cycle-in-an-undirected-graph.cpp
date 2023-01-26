//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node,int par,vector<int>&visited,vector<int>&parent,vector<int>adj[]){
        visited[node]=true;
        parent[node]=par;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int frnt=q.front();
            q.pop();
            for(auto neg:adj[frnt]){
                if(neg==parent[frnt]) continue;
                if(visited[neg]) return 1;
                else{
                    visited[neg]=true;
                    parent[neg]=frnt;
                    q.push(neg);
                }
            }
        }
        return 0;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        vector<int>visited(v,0);
        vector<int>parent(v,0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool cyc=bfs(i,-1,visited,parent,adj);
                if(cyc){
                    return true;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends