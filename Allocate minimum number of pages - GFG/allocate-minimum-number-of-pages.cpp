//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
   
   bool ispossible(int A[],int N,int M,int mid){
       int cnt=1;
       int sum=0;
       for(int i=0;i<N;i++){
           if(sum+A[i]<=mid){
               sum+=A[i];
           }
           else{
               cnt++;
               if(cnt>M || A[i]>mid) return false;
               sum=A[i];
           }
       }
       return true;
   }
   
   
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        int ans=-1;
        int s=0;
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
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