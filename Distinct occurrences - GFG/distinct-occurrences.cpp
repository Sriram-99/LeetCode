//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
#define MOD 1000000007
class Solution
{
    public:
    int solve(string S,string T,int index1,int index2,int n,int m,
    vector<vector<int>>&dp){
      if(index2==m ) return 1;
        if(index1==n) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int ans=0;
        if(S[index1]==T[index2]){
         ans+=solve(S,T,index1+1,index2+1,n,m,dp);   
        }
        ans+=solve(S,T,index1+1,index2,n,m,dp);
        return dp[index1][index2]= ans;
        
    }
    int solveTab(string &str,string &sub){
		int n=str.length();
        int m=sub.length();
		vector<vector<int>>dp(n+1,vector<int>(m+1,0));
		 for (int i = 0; i <= n; i++) {
        dp[i][m] = 1; 
        }
		for(int index1=n-1;index1>=0;index1--){
			for(int index2=m-1;index2>=0;index2--){
					int val=0;
					if(str[index1]==sub[index2]){
						val= (val+dp[index1+1][index2+1]%MOD)%MOD;
					}
					val=(val+dp[index1+1][index2]%MOD)%MOD;
					dp[index1][index2]=val;
			}
		}
		return dp[0][0];
	}
    int subsequenceCount(string S, string T)
    {
    //     int n=S.length();
    //     int m=T.length();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    // //   if(S=="" || T=="") return 0;
    //   return  solve(S,T,0,0,n,m,dp);
    return solveTab(S,T);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends