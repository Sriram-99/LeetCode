//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n, int m, vector<vector<int>>&mat,int &ans,int i,int j
    ,vector<vector<int>>&dp){
        if(i>=n || j>=m ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(n,m,mat,ans,i,j+1,dp);
        int down=solve(n,m,mat,ans,i+1,j,dp);
        int diagonal=solve(n,m,mat,ans,i+1,j+1,dp);
         if(mat[i][j]==0){
            dp[i][j]=0;
            return 0;
        }
        int val=min(right,min(down,diagonal));
        ans=max(val+1,ans);
        
        dp[i][j]=val+1;
        return val+1;
    }
    
    int solveTab(int n, int m, vector<vector<int>> mat){
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for( int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    int right=0,down=0,diagonal=0;
                if(i<n && j+1<m)
                 right=dp[i][j+1];
                 if(i+1<n && j<m)
                 down=dp[i+1][j];
                 if(i+1<n && j+1<m)
                 diagonal=dp[i+1][j+1];
                 int val=min(right,min(down,diagonal));
                 ans=max(val+1,ans);
                 dp[i][j]=val+1;
                }
                
            }
        }
        return ans;
        
    }
    int solveSpace(int n,int m,vector<vector<int>>&mat){
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        int ans=0;
       for(int i=n-1;i>=0;i--){
            for( int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    int right=0,down=0,diagonal=0;
                if(i<n && j+1<m)
                 right=curr[j+1];
                 if(i+1<n && j<m)
                 down=prev[j];
                 if(i+1<n && j+1<m)
                 diagonal=prev[j+1];
                 int val=min(right,min(down,diagonal));
                 ans=max(val+1,ans);
                 curr[j]=val+1;
                }
                else{
                    curr[j]=0;
                }
                
            }
            prev=curr;
        }
        return ans;
    }
    
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
      return solveSpace(n,m,mat);
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