//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int n,int arr[],int target,int index, vector<vector<int>>&dp){
        if(index==n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[index][target]!=-1) return dp[index][target];
        bool inc=solve(n,arr,target-arr[index],index+1,dp);
        bool exc=solve(n,arr,target,index+1,dp);
       return  dp[index][target] =(inc|| exc);
    }
    int equalPartition(int N, int arr[])
    {
        
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
          if(sum%2==1) return 0;
       
        vector<vector<int>>dp(N+1,vector<int>(sum/2+1,-1));
    
      return solve(N,arr,sum/2,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends