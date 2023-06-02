//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans="";
        int n=S.length();
        string word="";
        for(int i=n-1;i>=0;i--){
            if(S[i]=='.'){
                ans+=word;
                word="";
                ans+=".";
            }
            else{
                word=S[i]+word;
            }
        }
        ans+=word;
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends