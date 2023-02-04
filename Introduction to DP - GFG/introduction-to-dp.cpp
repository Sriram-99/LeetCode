//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
# define MOD 1000000007
 long long int dp[100001];
class Solution {
  public:
  long long int td(int n,vector<int>&dp){
      if(n==0) return 0;
      if(n==1) return 1;
      if(dp[n]!=-1) return dp[n];
      long long int val=(td(n-1,dp)+td(n-2,dp));
      dp[n]=val%MOD;
      return dp[n];
  }
    long long int topDown(int n) {
        vector<int>dp(n+1,-1);
        return td(n,dp);
    }
    long long int bottomUp(int n) {
          vector<int>dp(n+1,-1);
       return td(n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends