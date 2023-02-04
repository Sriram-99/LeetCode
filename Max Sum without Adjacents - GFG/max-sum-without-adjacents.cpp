//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int n){
	     
	     int prev2=0;
	     int prev1=arr[0];
	     for(int i=1;i<n;i++){
	         int inc=arr[i]+prev2;
	         int exc=prev1;
	        prev2=prev1;
	        prev1=max(inc,exc);
	     }
	     return prev1;
	}
	int findMaxSum(int *arr, int n) {
	    return solve(arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends