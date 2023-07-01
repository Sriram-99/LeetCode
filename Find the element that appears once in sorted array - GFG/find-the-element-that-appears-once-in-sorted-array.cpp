//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        if(n==1) return arr[0];
        int s=1;
        int e=n-2;
        if(n>=2){
            if(arr[0]!=arr[1]) return arr[0];
            else if(arr[n-1]!=arr[n-2]) return arr[n-1];
        }
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
                return arr[mid];
            }
            if(arr[mid]==arr[mid-1]){
                if(mid%2==0){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(mid%2==0){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends