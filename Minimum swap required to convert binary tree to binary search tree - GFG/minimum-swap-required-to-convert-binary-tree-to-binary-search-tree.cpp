//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
  void findinorder(vector<int>& a, vector<int>& A, int n, int index) {
    if (index >= n) return;
    
    findinorder(a, A, n, 2 * index + 1);
    A.push_back(a[index]);
    findinorder(a, A, n, 2 * index + 2);
}

    int minSwaps(vector<int>& a, int n) {
    vector<pair<int,int>> inorder;
    int cnt = 0;
    int index = 0;
    vector<int> A;
    findinorder(a, A, n, index);
    
    for (int i = 0; i < n; i++) {
        inorder.push_back(make_pair(A[i], i));
    }
    
    sort(inorder.begin(), inorder.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> curr = inorder[i];
        if (curr.second == i) continue;
        
        swap(inorder[i], inorder[curr.second]);
        ans++;
        
        if (inorder[i].second != i) i--;
    }
    
    return ans;
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends