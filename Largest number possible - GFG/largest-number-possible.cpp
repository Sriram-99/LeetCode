//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S==0 && N!=1) return "-1";
        if((9*N)<S) return "-1";
        int val=S;
        string ans="";
        for(int i=0;i<N;i++){
           if(val==0){
               ans+="0";
           }
           else{
               int temp1=val/9;
               int temp2=val%9;
               if(temp1==0){
                   ans+=to_string(temp2);
                   val=0;
               }
               else{
                   val=val-9;
                   ans+="9";
               }
           }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends