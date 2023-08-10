//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int n,int m,string s1,string s2,int index1,int index2, vector<vector<int>>&dp){
        if(index1==n || index2==m ) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s1[index1]==s2[index2]){
            return dp[index1][index2]= 1+solve(n,m,s1,s2,index1+1,index2+1,dp);
        }
        return dp[index1][index2]= max(solve(n,m,s1,s2,index1,index2+1,dp),solve(n,m,s1,s2,index1+1,index2,dp));
    }
    int solveTab(int n,int m,string s1,string s2){
        vector<int>prev(m,0);
        vector<int>curr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]){
                    if(j-1>=0)
                    curr[j]= 1+prev[j-1];
                    else{
                        curr[j]=1;
                    }
                }
                else{
                    if(j-1>=0)
                    curr[j]=max(curr[j-1],prev[j]);
                    else 
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return curr[m-1];
    }
    int lcs(int n, int m, string s1, string s2)
    {
    //     
    return solveTab(n,m,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends