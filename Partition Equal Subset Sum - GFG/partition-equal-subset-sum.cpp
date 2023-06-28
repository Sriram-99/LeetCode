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
    bool solveTab(int n,int arr[],int tar){
        
        vector<vector<bool>>dp(n+1,vector<bool>(tar+1,0));
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int index=n-1;index>=0;index--){
            for(int target=1;target<=tar;target++){
                bool inc =0;
                if(target-arr[index]>=0)
                 inc=dp[index+1][target-arr[index]];
                bool exc=dp[index+1][target];
                dp[index][target]=(inc || exc);
            }
        }
        return dp[0][tar];
    }
    
    bool solveSpace(int n,int arr[],int tar){
        vector<bool>next(tar+1,0);
        vector<bool>curr(tar+1,0);
        next[0]=1;
        curr[0]=1;
        for(int index=n-1;index>=0;index--){
            // curr[0]=1;
            // next[0]=1;
            for(int target=1;target<=tar;target++){
                bool inc =0;
                if(target-arr[index]>=0)
                 inc=next[target-arr[index]];
                bool exc=next[target];
                curr[target]=(inc || exc);
            }
            next=curr;
        }
        return curr[tar];
    }
    
    bool solveSpace2(int n,int arr[],int tar){
        vector<bool>curr(tar+1,0);
        
        curr[0]=1;
        for(int index=n-1;index>=0;index--){
            
            for(int target=tar;target>=1;target--){
                bool inc =0;
                if(target-arr[index]>=0)
                 inc=curr[target-arr[index]];
                bool exc=curr[target];
                curr[target]=(inc || exc);
            }
        }
        return curr[tar];
    }
    
    
    int equalPartition(int N, int arr[])
    {
        
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
          if(sum%2==1) return 0;
       
        // vector<vector<int>>dp(N+1,vector<int>(sum/2+1,-1));
    
      return solveSpace2(N,arr,sum/2);
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