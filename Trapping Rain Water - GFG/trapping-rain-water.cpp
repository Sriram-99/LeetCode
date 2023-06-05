//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int left[n];
        int right[n];
       int maxi1=INT_MIN;
       int maxi2=INT_MIN;
        for(int i=0;i<n;i++){
            maxi1=max(maxi1,arr[i]);
            left[i]=maxi1;
            maxi2=max(maxi2,arr[n-1-i]);
            right[n-1-i]=maxi2;
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
           if(left[i]>arr[i] && right[i]>arr[i]){
               ans+=min(left[i],right[i])-arr[i];
           } 
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends