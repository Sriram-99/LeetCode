//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        vector<int>prev(3,0);
        vector<int>curr(3,0);
        for(int i=0;i<3;i++){
            prev[i]=colors[0][i];
        }
        
        for(int i=1;i<N;i++){
            curr[0]=colors[i][0]+min(prev[1],prev[2]);
            curr[1]=colors[i][1]+min(prev[0],prev[2]);
            curr[2]=colors[i][2]+min(prev[0],prev[1]);
            prev=curr;
        }
        return min(curr[0],min(curr[1],curr[2]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends