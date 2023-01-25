//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   void dfs(int node,vector<int>adj[],vector<int>&ans,vector<int>&visited){
       visited[node]=1;
      ans.push_back(node);
      for(auto nb:adj[node]){
          if(!visited[nb]){
              dfs(nb,adj,ans,visited);
          }
      }
      
   }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>ans;
        vector<int>visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,adj,ans,visited);
            }
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends