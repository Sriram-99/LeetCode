//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void del(stack<int>&s,int cnt){
        if(cnt==1){
            s.pop();
            return;
        }
        int tp=s.top();
        s.pop();
        cnt--;
        del(s,cnt);
        s.push(tp);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int n)
    {
        if(n==0) return;
        if(n==1) {
            s.pop();
            return;
        }
        int mid;
        
            mid=n/2;
            mid+=1;
        
         del(s,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends