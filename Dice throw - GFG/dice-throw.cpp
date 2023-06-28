//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int faces,int dices,int target,vector<vector<long long>>&dp){
        //base case 
        if(faces==0 || target<0) return 0;
        if(dices==0 && target!=0 ) return 0;
        if(dices==0 && target==0) return 1;
        if(dp[dices][target]!=-1) return dp[dices][target];
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans+=solve(faces,dices-1,target-i,dp);
        }
        return dp[dices][target]=ans;
            
    }
    
    long long solveTab(int faces,int dices,int target){
        vector<vector<long long>>dp(dices+1,vector<long long>(target+1,0));
        //
        dp[0][0]=1;
        for(int index=1;index<=dices;index++){
            for(int value=1;value<=target;value++){
                long long sum=0;
                for(int i=1;i<=faces;i++){
                    if(value-i>=0){
                        sum+=dp[index-1][value-i];
                    }
                    
                }
                dp[index][value]=sum;
            }
        }
        return dp[dices][target];
    }
    long long noOfWays(int M , int N , int X) {
        // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        return solveTab(M,N,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends