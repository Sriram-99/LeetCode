//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  #define MOD 1000000007
    long long noOfWays(int M , int N , int X) {
       vector<vector<long long>>dp(N+1,vector<long long>(X+1,0));
       dp[0][0]=1;
       
        for(int val=1;val<=X;val++){
            for(int cnt=1;cnt<=N;cnt++ ){
                long long  val1=0;
                for(int i=1;i<=M;i++){
                    if(val-i>=0){
                         val1=(val1+dp[cnt-1][val-i]);
                    }
                }
                dp[cnt][val]=val1;
            }
        }
        return dp[N][X];
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