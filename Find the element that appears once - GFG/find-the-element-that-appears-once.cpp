//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    if(n==1)return arr[0];
	    if(n==0) return-1;
	    for(int i=0;i<n;i++){
	        if(i==n-1) return arr[i];
	        if(arr[i]!=arr[i+1]) return arr[i];
	        i++;
	    }
	    return -1;
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends