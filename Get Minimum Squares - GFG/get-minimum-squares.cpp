//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int minsq(int n,vector<int>&dp){
	    if(n==0) return 0;
	    if(n<0) return INT_MAX;
	    if(dp[n]!=-1) return dp[n];
	    int ans=INT_MAX;
	    for(int i=1;i*i<=n;i++){
	        int val=minsq(n-(i*i),dp);
	        if(val!=INT_MAX) ans=min(ans,val+1);
	    }
	    dp[n]=ans;
	    return ans;
	}
	int minsqTab(int n){
	    vector<int>dp(n+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<n+1;i++){
	        
	        for(int j=1;j*j<=i;j++){
	           int temp=j*j;
	           if((i-temp)>=0 && dp[i-j*j]!=INT_MAX){
	               dp[i]=min(dp[i],dp[i-j*j]+1);
	           }
	            
	        }
	       
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    return minsqTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends