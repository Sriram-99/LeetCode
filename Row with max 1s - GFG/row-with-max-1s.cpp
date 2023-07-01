//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
int rowWithMax1s(vector<vector<int>>& arr, int n, int m) {
    int ans = 0;
    int row = -1;
    int rowIndex = 0;
    int colIndex = m - 1;

    for (int i = 0; i < n; i++) {
        rowIndex = i;
        while (arr[rowIndex][colIndex] == 1) {
            colIndex--;
            if (colIndex == -1)
                return rowIndex;
        }
        if (ans < m - 1 - colIndex) {
            ans = m - 1 - colIndex;
            row = rowIndex;
        }
    }

    return row;
}


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends