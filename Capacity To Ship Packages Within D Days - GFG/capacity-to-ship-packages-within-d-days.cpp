//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // int calcnt(int arr[],int n,int d,int mid){
    //     int cnt=0;
    //     int load=0;
    //     for(int i=0;i<n;i++){
    //         if(load+arr[i]>mid){
    //             cnt++;
    //             load=0;
    //         }
    //         load+=arr[i];
    //     }
    //     if(load!=0) cnt++;
    //     return cnt;
    // }
    // int leastWeightCapacity(int arr[], int n, int d) {
    //     sort(arr,arr+n);
    //     int sum=0;
    //     int maxi=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         sum+=arr[i];
    //         maxi=max(maxi,arr[i]);
    //     }
    //     int s =maxi;
    //     int e=sum;
    //     int ans=sum;
    //     while(s<=e){
    //         int mid=(s+e)/2;
    //         int cnt=calcnt(arr,n,d,mid);
    //         if(cnt<=d){
    //             ans=min(ans,mid);
    //           e=mid-1;;
    //         }
    //         else{
    //           s=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    int calcnt(int arr[],int n,int d,int mid){
        int cnt=0;
        int load=0;
        for(int i=0;i<n;i++){
            if(load+arr[i]>mid){
                cnt++;
                load=0;
            }
            load+=arr[i];
        }
        if(load!=0) cnt++;
        return cnt;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
      
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int s =maxi;
        int e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            int cnt=calcnt(arr,n,d,mid);
            if(cnt<=d){
                ans=min(ans,mid);
              e=mid-1;;
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
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends