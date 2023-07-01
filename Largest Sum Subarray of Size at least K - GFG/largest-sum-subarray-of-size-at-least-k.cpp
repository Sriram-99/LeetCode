//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int ans=INT_MIN;
    long long int  maxi=0;
    long long int  curr=0;
    long long int  past=0;
    long long int pastidx=0;
    for(long long int i=0;i<n;i++){
        if(i<k){
            curr+=a[i];
            if(i==k-1) ans=max(ans,curr);
            continue;
        }
        curr+=a[i]-a[i-k];
         past+=a[i-k];
         maxi+=a[i-k];
         
    if(i!=k){
       past=past-a[pastidx];
             pastidx++;
              maxi=max(past,maxi);
         ans=max(ans,max(curr,curr+maxi));
    }
    else{
        ans=max(ans,max(curr,curr+a[0]));
    }
            
    }
    return ans;
}
