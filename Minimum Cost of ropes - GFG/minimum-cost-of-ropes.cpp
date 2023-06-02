//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long,vector<long long>,greater<long long>>vvi;
       
       long long ans=0;
       if(n==0) return 0;
       if(n==1) return 0;
       for(long long i=0;i<n;i++){
           vvi.push(arr[i]);
       }
       while(vvi.size()!=1){
           long long tp1=vvi.top();
           vvi.pop();
           long long  tp2=vvi.top();
           vvi.pop();
           long long sm=tp1+tp2;
           ans+=sm;
           vvi.push(sm);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends