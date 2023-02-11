//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string comm(string s1,string s2){
        int l1=s1.length();
        int l2=s2.length();
        string ans="";
        for(int i=0;i<l1 && i<l2;i++){
          if(s1[i]==s2[i]) ans+=s1[i];
          else{
              break;
          }
        }
        return ans;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        string temp=arr[0];
     for(int i=1;i<N;i++){
         string s1=arr[i];
         temp=comm(temp,s1);
     }
       if(temp.length()==0) return "-1";
       return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends