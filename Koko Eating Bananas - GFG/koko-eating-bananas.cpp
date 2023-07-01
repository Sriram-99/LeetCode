//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int checker(long long  mid,vector<int>&piles,int n,int H){
        long long  count=0;
        for(int i=0;i<n;i++){
            int val=piles[i];
            int cnt=val/mid;
            int rm=val%mid;
            count+=cnt;
            if(rm!=0) count+=1;
            if(count>H) return 2;
        }
       if(count==H) return 1;
       return 0;
    }
    int Solve(int N, vector<int>& piles, int H) {
       int sum=0;
        for(int i=0;i<N;i++){
            sum=max(piles[i],sum);
        }
        long long s=0;
        long long  e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            int cnt=checker(mid,piles,N,H);

          if(cnt<=1){
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends