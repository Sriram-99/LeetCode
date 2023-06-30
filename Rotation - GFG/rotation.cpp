//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findMin(int arr[], int n){
        int s=0;
        int e=n-1;
        int mid;
        if(arr[s]<arr[e]) return s;
        while(s<=e){
          mid=(s+e)/2;
          if(arr[mid]>=arr[0]){
              s=mid+1;
          }
          else{
              if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]) return mid;
              else e=mid-1;
          }
        }
        return mid;
    }
	int findKRotation(int arr[], int n) {
	    int index=findMin(arr,n);
	    return index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends