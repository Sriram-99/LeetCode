//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool ispossible(int arr[],int n,int m,int mid){
        int cnt=1;
        int val=0;
        
        for(int i=0;i<n;i++){
            if(val+arr[i]<=mid){
                val+=arr[i];
            }
            else{
                cnt++;
                if(cnt>m || arr[i]>mid) return false;
                val=arr[i];
            }
        }
       if(cnt<m) false ;
       return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
       int sum=0;
       for(int i=0;i<N;i++){
           sum+=A[i];
       }
       
       int s=1;
        int e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            if(ispossible(A,N,M,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
       if(ans==INT_MAX) return -1;
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends