//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int>ans;
      sort(candies,candies+N);
      if(K>N){
          ans.push_back(candies[0]);
          ans.push_back(candies[N-1]);
          return ans;
      }
      int cnt=0;
        int total=N;
            int q=N/(K+1);
            int r=N%(K+1);
            cnt=q;
            if(r>0){
                cnt++;
            }
      int mini=0,maxi=0;
      for(int i=0;i<cnt;i++){
          mini+=candies[i];
          maxi+=candies[N-1-i];
      }
      ans.push_back(mini);
      ans.push_back(maxi);
      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends