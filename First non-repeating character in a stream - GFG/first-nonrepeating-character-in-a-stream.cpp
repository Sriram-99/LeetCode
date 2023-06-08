//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   int n=A.length();
		   if(n<2) return A;
		   vector<int>visited(26,0);
		   vector<char>vvi;
		   string ans="";
		   for(int i=0;i<n;i++){
		       if(visited[A[i]-'a']==0){
		           vvi.push_back(A[i]);
		       }
		       visited[A[i]-'a']++;
		       int f=0;
		       int m=vvi.size();
		       for(int i=0;i<m;i++){
		           if(visited[vvi[i]-'a']==1){
		               f=1;
		               ans.push_back(vvi[i]);
		               break;
		           }
		       }
		       if(!f){
		           ans.push_back('#');
		       }
		       
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends