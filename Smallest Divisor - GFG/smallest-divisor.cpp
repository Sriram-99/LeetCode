//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool ispossible(vector<int>& nums,int k,int mid ,int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i]/mid;
            if(nums[i]%mid!=0) ans+=1;
            
        }
        if(ans<=k) return 1;
        return 0;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n=nums.size();
        if(k<n) return -1;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        
        int s=1;
        int e=maxi;
        int ans=maxi;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,k,mid,n)){
                ans=min(ans,mid);
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends