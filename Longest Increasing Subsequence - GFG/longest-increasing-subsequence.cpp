//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find length of longest increasing subsequence.
    int solve(int n, int arr[], int prev, int index, vector<vector<int>>& dp) {
        if (index == n)
            return 0;
        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        int inc = 0;
        if (prev == -1 || arr[index] > arr[prev]) {
            inc = 1 + solve(n, arr, index, index + 1, dp); // corrected parameter
        }
        int exc = 0 + solve(n, arr, prev, index + 1, dp);
        dp[index][prev + 1] = max(inc, exc);
        return dp[index][prev + 1];
    }

    int solveTab(int n,int arr[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0 ));
        for(int index=n-1;index>=0;index--){
            for(int prev=-1;prev<n;prev++){
                int inc =0;
                if(prev==-1 || arr[prev]<arr[index]){
                    inc=1+dp[index+1][index+1];
                }
                int exc=dp[index+1][prev+1];
                dp[index][prev+1]=max(inc,exc);
            }
        }
        return dp[0][0];
    }
    
    int optimal(int n,int arr[]){
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(ans.back()<arr[i]) ans.push_back(arr[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int arr[]) {
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // int prev = -1;
        // return solve(n, arr, prev, 0, dp);
        return optimal(n,arr);
    }
    
    
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends