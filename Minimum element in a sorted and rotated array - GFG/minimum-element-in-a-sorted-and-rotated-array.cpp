//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int s=0;
        int e=n-1;
        int mid;
        if(arr[s]<arr[e]) return arr[s];
        while(s<=e){
          mid=(s+e)/2;
          if(arr[mid]>=arr[0]){
              s=mid+1;
          }
          else{
              if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]) return arr[mid];
              else e=mid-1;
          }
        }
        return arr[mid];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends