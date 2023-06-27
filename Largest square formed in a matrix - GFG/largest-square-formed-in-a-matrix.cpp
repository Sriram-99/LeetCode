//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(vector<vector<int>>& MAT, int n, int m,int i,int j,int&ans,vector<vector<int>>& dp){
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=solve(MAT,n,m,i,j+1,ans,dp);
    int down=solve(MAT,n,m,i+1,j,ans,dp);
    int diag=solve(MAT,n,m,i+1,j+1,ans,dp);
    int val=0;
    if(MAT[i][j]==1){
      val=1+min(right,min(down,diag));
        ans=max(ans,val);
        
    }
    dp[i][j]=val;
     return dp[i][j];
}
    int maxSquare(int n, int m, vector<vector<int>>MAT){
         int ans=0;
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   solve(MAT,n,m,0,0,ans,dp);
   return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends