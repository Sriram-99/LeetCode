//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int mincost(vector<int>&cost,vector<int>&vvi,int N,int i){
      if(i==0){
          return cost[0];
      }
      if(i==1) return cost[1];
      if(vvi[i]!=-1) return vvi[i];
      vvi[i]=min(mincost(cost,vvi,N,i-1),mincost(cost,vvi,N,i-2))+cost[i];
      return vvi[i];
  }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
            vector<int>vvi(N,-1);
         return min(mincost(cost,vvi,N,N-1),mincost(cost,vvi,N,N-2));
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends