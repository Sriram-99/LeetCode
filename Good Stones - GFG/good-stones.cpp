//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    bool good(int n ,vector<int>&arr, int pos ,vector<int>&dp,vector<bool>&dfs){
       if(pos>=n || pos<0) return true;
       if(dp[pos]!=-1) return dp[pos];
       if(dfs[pos]==true) return false;
       dfs[pos]=true;
       int inx=pos+arr[pos];
       bool ans=good(n,arr,inx,dp,dfs);
       dfs[pos]=false;
      if(ans==true)dp[pos]=1;
    else dp[pos]=0;
       return ans;
       
    }
    int goodStones(int n,vector<int> &arr){
       vector<int>dp(n,-1);
       vector<bool>dfs(n,false);
       int cnt=0;
       for(int i=0;i<n;i++){
           if(dp[i]==-1){
               good(n,arr,i,dp,dfs);
           }
           cnt+=dp[i];
       }
       
       
       return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends