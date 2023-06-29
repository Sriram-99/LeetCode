//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int solve(int arr[],int n){
    int dif=arr[n-1]-arr[0];
    int maxi=0;
    vector<vector<int>>dp(n+1,vector<int>(dif+1,0));
    for(int index=n-1;index>=0 ;index--){
       for(int pos=index+1;pos<n;pos++){
           int val=arr[pos]-arr[index];
           int ans=1+dp[pos][val];
           maxi=max(ans,maxi);
           dp[index][val]=ans;
       }
    }
    return maxi;
}
    int lengthOfLongestAP(int A[], int n) {
      return 1+solve(A,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends